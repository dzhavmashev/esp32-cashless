// Function : FUN_401217a4
// Address  : 0x401217a4
// Size     : 38 bytes


undefined4 FUN_401217a4(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x102;
  if (param_1 < 2) {
    iVar1 = (*(code *)&SUB_40091700)();
    uVar2 = 0x103;
    if (iVar1 == 2) {
      uVar2 = FUN_40121644(param_1,param_2,param_3,0);
    }
  }
  return uVar2;
}

