// Function : FUN_400e6370
// Address  : 0x400e6370
// Size     : 105 bytes


void FUN_400e6370(uint *param_1,uint param_2,uint param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_400e635c(param_1);
  if (-1 < (int)*param_1) {
    FUN_400f1960(*param_1 & 0xff,5);
    FUN_400e627c(param_1,0,*param_1);
    FUN_400f06a4(0x3ffc5490,"r reset",*param_1);
  }
  if ((int)param_1[1] < 0) {
    FUN_400f0780(0x3ffc5490,"nit 1)\n");
  }
  else {
    FUN_400f1960(param_1[1] & 0xff,5);
    FUN_400e627c(param_1,1,param_1[1]);
    FUN_400f06a4(0x3ffc5490,"nit 0)\n",param_1[1]);
  }
  FUN_400f06a4(0x3ffc5490,"igured)");
  return;
}

