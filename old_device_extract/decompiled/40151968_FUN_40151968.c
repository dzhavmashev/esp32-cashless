// Function : FUN_40151968
// Address  : 0x40151968
// Size     : 60 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40151968(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_3ffc8a34 != '\0') {
    FUN_401518bc();
    return 0x3002;
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  *_DAT_3ffc8fd8 = param_1;
  _DAT_3ffc8fd8 = (int *)(param_1 + 0x28);
  memw();
  iVar1 = (*(code *)&SUB_40087bcc)(5,0);
  uVar2 = 0x3012;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}

