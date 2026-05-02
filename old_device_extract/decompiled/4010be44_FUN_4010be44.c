// Function : FUN_4010be44
// Address  : 0x4010be44
// Size     : 89 bytes


void FUN_4010be44(int *param_1,int param_2)

{
  short sVar1;
  short in_t0;
  
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    while( true ) {
      if ((int *)*param_1 == (int *)0x0) break;
      *(short *)(param_1 + 2) = (short)param_1[2] + *(short *)(param_2 + 8);
      memw();
      param_1 = (int *)*param_1;
    }
    sVar1 = *(short *)((int)param_1 + 10);
    if (sVar1 != (short)param_1[2]) {
      memw();
      sVar1 = in_t0;
      (*(code *)&SUB_40094c54)("if_init",0x36b,"al_pbuf","verflow");
    }
    *(short *)(param_1 + 2) = sVar1 + *(short *)(param_2 + 8);
    memw();
    *param_1 = param_2;
    memw();
  }
  return;
}

