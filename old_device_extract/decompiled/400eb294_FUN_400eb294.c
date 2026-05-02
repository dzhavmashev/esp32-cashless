// Function : FUN_400eb294
// Address  : 0x400eb294
// Size     : 241 bytes


undefined4
FUN_400eb294(int param_1,undefined4 param_2,char param_3,undefined1 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  char cStack_29;
  undefined4 *puStack_28;
  int iStack_24;
  
  iVar1 = FUN_40184464(param_1 + 0xb0);
  if (4 < iVar1) {
    return 0;
  }
  func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
  uVar2 = 1;
  if (param_3 != '\0') {
    uVar2 = FUN_40184424(param_1);
  }
  cStack_29 = '\0';
  puStack_28 = (undefined4 *)(*(code *)&LAB_4016fa0f_1)(0x30,&DAT_3f424b88);
  if (puStack_28 == (undefined4 *)0x0) {
    iStack_24 = 0;
  }
  else {
    *puStack_28 = 0;
    FUN_400ebfa4(puStack_28 + 1,&cStack_29,uVar2,param_2,param_5,param_6,param_3,param_4);
    puStack_28[0xb] = 0;
    if (*(int *)(param_1 + 0x678) == 0) {
      *(undefined4 **)(param_1 + 0x680) = puStack_28;
      *(undefined4 **)(param_1 + 0x678) = puStack_28;
      iStack_24 = 0;
    }
    else {
      iStack_24 = *(int *)(param_1 + 0x67c);
      *(undefined4 **)(iStack_24 + 0x2c) = puStack_28;
    }
    *(undefined4 **)(param_1 + 0x67c) = puStack_28;
    if (*(int *)(param_1 + 0x680) == 0) {
      *(undefined4 **)(param_1 + 0x680) = puStack_28;
    }
  }
  if (puStack_28 != (undefined4 *)0x0) {
    if (cStack_29 == '\0') goto LAB_400eb352;
    FUN_400dad2c(param_1 + 0x678,&puStack_28);
  }
  func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
  (*(code *)&LAB_4018443f_1)(param_1,uVar2,1);
  func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
  uVar2 = 0;
LAB_400eb352:
  func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
  return uVar2;
}

