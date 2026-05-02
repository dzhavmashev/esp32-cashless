// Function : FUN_4010bd2c
// Address  : 0x4010bd2c
// Size     : 155 bytes


void FUN_4010bd2c(int *param_1,uint param_2)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  param_2 = param_2 & 0xffff;
  if (param_1 != (int *)0x0) goto LAB_4010bd46;
  pcVar5 = "us type";
  uVar4 = 0x19c;
LAB_4010bd3d:
  do {
    (*(code *)&SUB_40094c54)("if_init",uVar4,"er_impl",pcVar5);
LAB_4010bd46:
    uVar1 = *(ushort *)(param_1 + 2);
    if (uVar1 <= param_2) {
LAB_4010bdc5:
      memw();
      return;
    }
    sVar2 = (short)param_2;
    do {
      uVar3 = (uint)*(ushort *)((int)param_1 + 10);
      if (param_2 <= uVar3) {
        if (((((*(byte *)(param_1 + 3) & 0xf) == 0) && (uVar3 != param_2)) &&
            ((*(byte *)((int)param_1 + 0xd) & 2) == 0)) &&
           (param_1 = (int *)FUN_40185304(param_1,(param_1[1] - (int)param_1) + param_2),
           param_1 == (int *)0x0)) {
          pcVar5 = "!= NULL";
          uVar4 = 0x1c1;
          goto LAB_4010bd3d;
        }
        *(short *)((int)param_1 + 10) = (short)param_2;
        *(short *)(param_1 + 2) = (short)param_2;
        memw();
        if (*param_1 != 0) {
          memw();
          FUN_4010bb10();
        }
        *param_1 = 0;
        goto LAB_4010bdc5;
      }
      param_2 = param_2 - uVar3 & 0xffff;
      *(ushort *)(param_1 + 2) = (sVar2 - uVar1) + (short)param_1[2];
      memw();
      param_1 = (int *)*param_1;
    } while (param_1 != (int *)0x0);
    pcVar5 = "!= NULL";
    uVar4 = 0x1b3;
    memw();
  } while( true );
}

