// Function : FUN_401592b4
// Address  : 0x401592b4
// Size     : 101 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401592b4(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(_DAT_3ffc8800 + 0xe4);
  if (iVar1 == 0) {
    FUN_40147fe4(1,0x10004,2,0x3f436c07);
    return;
  }
  iVar2 = _DAT_3ffc8800 + 0x2c;
  (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar2);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar2);
  FUN_40147fe4(1,0x40,3,0x3f434f6f,*(undefined4 *)(iVar1 + 0x300));
  *(undefined4 *)(iVar1 + 0x300) = 0;
  *(undefined1 *)(iVar1 + 0x2fb) = 0;
  memw();
  memw();
  FUN_40157594(&DAT_3ffc87f0,0,0xd100);
  return;
}

