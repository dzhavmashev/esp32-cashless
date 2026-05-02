// Function : FUN_40106118
// Address  : 0x40106118
// Size     : 53 bytes


int FUN_40106118(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  if ((param_2 == 0 || param_4 == 0) || (param_3 != param_5)) {
    iVar1 = -1;
  }
  else {
    iVar1 = (*(code *)&SUB_4008b33c)(param_2,param_4,param_3);
    iVar1 = -(uint)(iVar1 != 0);
  }
  return iVar1;
}

