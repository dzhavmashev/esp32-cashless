// Function : FUN_40165abc
// Address  : 0x40165abc
// Size     : 93 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40165abc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = _DAT_3ffc06fc;
  iVar3 = 0;
  iVar2 = _DAT_3ffc06fc;
  do {
    if (iVar2 == 0) break;
    iVar4 = *(int *)(iVar2 + 8);
    if (*(int *)(iVar2 + 4) != 0) {
      (**(code **)(_DAT_3ffc1a34 + 0xb0))();
      *(undefined4 *)(iVar2 + 4) = 0;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar4;
  } while (iVar1 != iVar4);
  _DAT_3ffc06fc = 0;
  memw();
  FUN_40147fe4(6,1,3,0x3f435af8,iVar3);
  if (_DAT_3ffc0704 != 0) {
    (**(code **)(_DAT_3ffc1a34 + 0xb0))();
    _DAT_3ffc0704 = 0;
  }
  memw();
  return;
}

