// Function : FUN_4015d5b0
// Address  : 0x4015d5b0
// Size     : 148 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015d5b0(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined1 auStack_30 [48];
  
  iVar1 = _DAT_3ffbfc54;
  iVar2 = *(int *)(_DAT_3ffc8800 + 0xe4);
  FUN_4014eb04(0,auStack_30);
  if (iVar2 == 0) {
    *(undefined1 *)(_DAT_3ffc8800 + 0x94) = 5;
    memw();
    memw();
  }
  else {
    FUN_401614cc();
    puVar3 = &DAT_3f4239bb;
    if (*(byte *)(_DAT_3ffc8800 + 0x94) < 3) {
      puVar3 = (undefined *)(iVar2 + 4);
    }
    memw();
    iVar1 = FUN_40153c94(iVar2,auStack_30,puVar3,puVar3,iVar1 + 8,*(uint *)(iVar1 + 4) & 0xff,0,0);
    if (iVar1 != 0) {
      FUN_40161690();
    }
  }
  *(char *)(_DAT_3ffc8800 + 0x94) = *(char *)(_DAT_3ffc8800 + 0x94) + '\x01';
  memw();
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0xec))();
  (**(code **)(_DAT_3ffc1a34 + 0xe8))(_DAT_3ffc8800 + 0x18,500,0);
  return;
}

