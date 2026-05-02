// Function : FUN_40162224
// Address  : 0x40162224
// Size     : 76 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162224(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  (**(code **)(_DAT_3ffc1a34 + 0x1b0))(0,0xffff);
  (**(code **)(_DAT_3ffc1a34 + 0x1b4))(0,param_1);
  if (param_1 == 0) {
    uVar2 = 1000;
    pcVar1 = *(code **)(_DAT_3ffc1a34 + 0x1b8);
    memw();
  }
  else {
    if ((param_1 != 1) && (param_1 != 2)) {
      _DAT_3ffca368 = param_1;
      return;
    }
    uVar2 = 100;
    pcVar1 = *(code **)(_DAT_3ffc1a34 + 0x1b8);
  }
  _DAT_3ffca368 = param_1;
  (*pcVar1)(uVar2);
  return;
}

