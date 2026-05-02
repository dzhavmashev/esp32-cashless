// Function : FUN_40146ec4
// Address  : 0x40146ec4
// Size     : 55 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40146ec4(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_401460c8();
  uVar2 = 0x3001;
  if (((iVar1 != 0) && (uVar2 = 0x3004, param_1 < 2)) && (uVar2 = 0x102, param_2 != 0)) {
    if (param_1 == 0) {
      uVar2 = FUN_401460f4(param_2);
    }
    else if (*(code **)(_DAT_3ffc87ec + 0x18) != (code *)0x0) {
      uVar2 = (**(code **)(_DAT_3ffc87ec + 0x18))(param_2);
    }
  }
  return uVar2;
}

