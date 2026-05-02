// Function : FUN_400f008c
// Address  : 0x400f008c
// Size     : 146 bytes


void FUN_400f008c(undefined4 *param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 1000;
  *param_1 = &DAT_3f40a4c4;
  param_1[6] = 0x100;
  *(char *)(param_1 + 4) = param_2;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[10] = 0;
  param_1[0xe] = 0;
  *(undefined2 *)(param_1 + 0x10) = 0x200;
  *(undefined1 *)((int)param_1 + 0x42) = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  iVar1 = func_0x4008fcd0(1);
  param_1[0x12] = iVar1;
  if (iVar1 == 0) {
    uVar4 = func_0x40085c04();
    uVar2 = (*(code *)&SUB_4000cff8)((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),1000,0);
    uVar3 = FUN_401847ec("nternal");
    FUN_4012105c("ial.cpp",uVar2,uVar3,0x58,"entTask");
  }
  else if (param_2 == '\0') {
    FUN_400f26ac(0,3,1,0xffffffff);
  }
  return;
}

