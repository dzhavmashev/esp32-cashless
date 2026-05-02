// Function : FUN_4015c280
// Address  : 0x4015c280
// Size     : 72 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015c280(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffc8800 + 0x68);
  iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
  iVar1 = _DAT_3ffc8800;
  if ((iVar2 != 0) && (*(char *)(_DAT_3ffc8800 + 0x7c) != '\0')) {
    pcVar3 = *(code **)(_DAT_3ffc1a34 + 0xf8);
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x1c0))();
    (*pcVar3)(iVar1 + 0x68,iVar2 * 10000,0);
    FUN_4016221c();
  }
  return;
}

