// Function : FUN_401268b8
// Address  : 0x401268b8
// Size     : 64 bytes


void FUN_401268b8(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_4008b33c)(param_1,param_2,6);
  if (iVar1 < 1) {
    (*(code *)&SUB_4008b3d0)(param_3,param_2,6);
  }
  else {
    (*(code *)&SUB_4008b3d0)(param_3,param_1);
    param_1 = param_2;
  }
  (*(code *)&SUB_4008b3d0)(param_3 + 6,param_1,6);
  return;
}

