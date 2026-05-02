// Function : FUN_40123890
// Address  : 0x40123890
// Size     : 48 bytes


undefined4 FUN_40123890(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4015a398();
  uVar3 = 0;
  if ((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 0x18), uVar3 = 0, iVar2 != 0)) {
    if (*(int *)(iVar2 + 0x54) == 0) {
      uVar3 = 0;
    }
    else {
      *param_1 = (char)*(undefined4 *)(iVar2 + 0x58);
      memw();
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x18) + 0x54);
    }
  }
  memw();
  return uVar3;
}

