// Function : FUN_40165674
// Address  : 0x40165674
// Size     : 100 bytes


int FUN_40165674(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == '\0') {
    FUN_40147fe4(6,0x800,3,0x3f435b6f);
    memw();
    memw();
    DAT_3ffc072c = param_1;
    FUN_40167664();
    FUN_401655c8(0);
    FUN_40165458(0);
    uVar2 = 0;
  }
  else {
    FUN_40147fe4(6,0x800,3,0x3f435b82);
    DAT_3ffc072c = '\x01';
    memw();
    memw();
    FUN_401675d8();
    iVar1 = FUN_401655c8(1);
    if (iVar1 != 0) {
      return iVar1;
    }
    FUN_40165458(1);
    uVar2 = 1;
  }
  FUN_40165638(uVar2);
  return 0;
}

