// Function : FUN_4015908c
// Address  : 0x4015908c
// Size     : 130 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015908c(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = DAT_3ffc89c4;
  iVar1 = _DAT_3ffc8800;
  if ((_DAT_3ffc8800 != 0) && ((*(uint *)(_DAT_3ffc8800 + 0x154) & 0x200) != 0)) {
    FUN_40147fe4(1,4,4,0x3f433bc3,*(undefined1 *)(_DAT_3ffc8800 + 0x154),0);
    *(undefined1 *)(_DAT_3ffc8800 + 0x154) = 0;
    memw();
    *(byte *)(iVar1 + 0x155) = *(byte *)(iVar1 + 0x155) & 0xfd;
    memw();
    memw();
    FUN_4014f5cc(0);
    FUN_4015fc30(0,1,0,0,bVar2 >> 4 & 1,DAT_3ffc89c0);
    FUN_401677fc();
    FUN_401561c0();
    if (_DAT_3ffc89a4 != 0) {
      (**(code **)(_DAT_3ffc89a4 + 4))();
    }
    FUN_40147240(3,0);
  }
  return 0;
}

