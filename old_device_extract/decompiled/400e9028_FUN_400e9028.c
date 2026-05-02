// Function : FUN_400e9028
// Address  : 0x400e9028
// Size     : 39 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e9028(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_3ffc5174;
  for (iVar2 = _DAT_3ffc5170; iVar1 != iVar2; iVar2 = iVar2 + 0x20) {
    (*(code *)&LAB_40183a17_1)(iVar2 + 8);
  }
  if (_DAT_3ffc5170 != 0) {
    FUN_4016fa48();
  }
  return;
}

