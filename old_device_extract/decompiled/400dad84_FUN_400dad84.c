// Function : FUN_400dad84
// Address  : 0x400dad84
// Size     : 127 bytes


undefined4 FUN_400dad84(int param_1,undefined2 *param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  char cStack_29;
  undefined4 *puStack_28;
  int iStack_24;
  
  cStack_29 = '\0';
  puStack_28 = (undefined4 *)(*(code *)&LAB_4016fa0f_1)(0x30,&DAT_3f424b88);
  if (puStack_28 == (undefined4 *)0x0) {
    iStack_24 = 0;
  }
  else {
    *puStack_28 = 0;
    FUN_400ec0c4(puStack_28 + 1,&cStack_29,*param_2,*param_3,*param_4);
    iVar2 = *(int *)(param_1 + 0x678);
    puStack_28[0xb] = 0;
    if (iVar2 == 0) {
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
  uVar1 = 0;
  if ((puStack_28 != (undefined4 *)0x0) && (uVar1 = 1, cStack_29 != '\0')) {
    FUN_400dad2c(param_1 + 0x678,&puStack_28);
    uVar1 = 0;
  }
  return uVar1;
}

