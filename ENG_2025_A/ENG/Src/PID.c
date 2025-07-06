#include "Includes.h"

#define SECOND				0		//秒
#define MILLISECOND		1		//毫秒
#define MICROSECOND		2		//微秒

void GetDt(TimeTD *time, uint32_t time_unit);
void float_constraint(float *data,float max,float min);
void pidTimeInit(TimeTD *time);

void pidInit (PidTD* pid, 
							const float iLimit,
							const float outLimit,
							const float kp,
							const float ki,
							const float kd)
{
	pidTimeInit(&pid->time);
	pid->first_cal	= true;
	pid->error			= 0;
	pid->lastError  = 0;
	pid->prevError	= 0;
	pid->integ			= 0;
	pid->deriv			= 0;
	pid->outPID			= 0;
	pid->desired		= 0;
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
	pid->iLimit    = iLimit;
	pid->iLimitLow = -iLimit;
	pid->outLimit = outLimit;
	pid->outLimitLow = -outLimit;
    pid->pid_calculate = pid_calculate;
}

void pidParameterSet(PidTD* pid,float kp,float ki,float kd)
{
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
}

//位置式pid计算
void pid_calculate(PidTD* pid,float desired,float measured)
{
	GetDt(&pid->time, SECOND);
	if(pid->first_cal == true)
	{
	    pid->first_cal = false;
	    pid->time.dt = 0.01;//积分或微分的步长，本质上也是系数，可以与Ki，Kd两个参数融合使用
	}
	pid->desired = desired;
	pid->error = pid->desired - measured;
  
	pid->integ += pid->error * pid->time.dt;//计算误差对时间的积分
  
	//计算误差对时间的微分
	if(pid->time.dt != 0){
		pid->deriv = (pid->error - pid->lastError) / pid->time.dt;
	}
	else{
		pid->deriv = 0;
	}
	
	pid->outP = pid->kp * pid->error;
	pid->outI = pid->ki * pid->integ;
	pid->outD = pid->kd * pid->deriv;
	float_constraint(&pid->outI,pid->iLimit,pid->iLimitLow);
	pid->outPID = pid->outP + pid->outI + pid->outD;
	float_constraint(&pid->outPID,pid->outLimit,pid->outLimitLow);
  
	pid->prevError = pid->lastError;
	pid->lastError = pid->error;
}

//增量式pid计算
void pid_calculate_inc(PidTD* pid,float desired,float measured){
	float increase_p = 0;
	float increase_i = 0;
	float increase_d = 0;
	
	GetDt(&pid->time, SECOND);
  if(pid->first_cal == true)
  {
    pid->first_cal = false;
    pid->time.dt = 0.01;
  }
  pid->desired = desired;
  pid->error = pid->desired - measured;
	
	increase_p = pid->kp * (pid->error - pid->lastError);
	increase_i = pid->ki * pid->error;
	increase_d = pid->kd * (pid->error - 2*pid->lastError + pid->prevError);
	
	pid->outP += increase_p;
	pid->outI += increase_i;
	pid->outD += increase_d;
	
	float_constraint(&pid->outI,pid->iLimit,pid->iLimitLow);
	pid->outPID = pid->outP + pid->outI + pid->outD;
	float_constraint(&pid->outPID,pid->outLimit,pid->outLimitLow);
	
	pid->prevError = pid->lastError;
	pid->lastError = pid->error;
}


void pidTimeInit(TimeTD *time){
	time->dt = 0.01f;
	time->timer_cnt_last = 0;
	time->timer_cnt_now = 0;
	time->timer_cnt_total = 0;
}

void float_constraint(float *data,float max,float min)
{
	if(*data>max)*data=max;
	else if(*data<min)*data=min;
}

