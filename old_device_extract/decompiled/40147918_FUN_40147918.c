// Function : FUN_40147918
// Address  : 0x40147918
// Size     : 190 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40147918(void)

{
  int iVar1;
  int iVar2;
  
  if (_DAT_3ffc8800 == 0) {
    iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x178))(0x23c);
    if (iVar1 == 0) {
      return 0x101;
    }
    *(undefined4 *)(iVar1 + 0x14c) = 0;
    *(undefined4 *)(iVar1 + 0x98) = 0;
    *(undefined1 *)(iVar1 + 0x168) = *(undefined1 *)(_DAT_3ffbfc54 + 0x9c);
    *(undefined2 *)(iVar1 + 0x23a) = 6;
    memw();
    memw();
    _DAT_3ffc8800 = iVar1;
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x178))(0x3a8);
    *(int *)(iVar1 + 0xe8) = iVar2;
    if (iVar2 == 0) {
      (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar1);
      _DAT_3ffc8800 = iVar2;
      memw();
      return 0x101;
    }
    memw();
    (*(code *)&SUB_4008b3d0)(iVar2 + 4,&DAT_3f4239bb,6);
    FUN_4015469c(iVar1,*(undefined1 *)(iVar1 + 0x168));
    **(int **)(iVar1 + 0xe8) = iVar1;
    if (*(char *)(iVar1 + 0x168) == '\x03') {
      memw();
      FUN_4014a9bc(iVar1);
    }
    FUN_4015fb80(0x4018a794,0);
    FUN_4015fba0(0x40158368);
    FUN_401594a4(iVar1);
  }
  FUN_40160064(0,_DAT_3ffc8800);
  return 0;
}

