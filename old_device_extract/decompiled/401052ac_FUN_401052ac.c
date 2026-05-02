// Function : FUN_401052ac
// Address  : 0x401052ac
// Size     : 34 bytes


int FUN_401052ac(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_40094d60)(param_2);
  if ((iVar1 != 0) && (param_1 != 0)) {
    iVar1 = (*(code *)&SUB_4008b3d0)(iVar1,param_1,param_2);
  }
  return iVar1;
}

