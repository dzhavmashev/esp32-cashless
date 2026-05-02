// Function : FUN_401453cc
// Address  : 0x401453cc
// Size     : 158 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401453cc(void)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  
  if ((_DAT_3ffc190c == 0) &&
     (_DAT_3ffc190c = (**(code **)(_DAT_3ffc17c4 + 0x18))(1), _DAT_3ffc190c == 0)) {
    memw();
    uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
    FUN_40168698(0x3ffc1849,uVar1);
  }
  else {
    if ((_DAT_3ffc18fc == 0) &&
       (_DAT_3ffc18fc = (**(code **)(_DAT_3ffc17c4 + 4))(), _DAT_3ffc18fc == 0)) {
      memw();
      uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
      FUN_40168698(0x3ffc1822,uVar1);
      pcVar2 = *(code **)(_DAT_3ffc17c4 + 0x1c);
      iVar3 = _DAT_3ffc190c;
    }
    else {
      iVar3 = FUN_40145d84();
      if (iVar3 == 0) {
        return 0;
      }
      uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
      FUN_40168698(0x3ffc1802,uVar1);
      (**(code **)(_DAT_3ffc17c4 + 0x1c))(_DAT_3ffc190c);
      pcVar2 = *(code **)(_DAT_3ffc17c4 + 8);
      iVar3 = _DAT_3ffc18fc;
    }
    (*pcVar2)(iVar3);
  }
  return 0x101;
}

