// Function : FUN_40102df8
// Address  : 0x40102df8
// Size     : 94 bytes


void FUN_40102df8(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0x1c0) == param_1) {
    (*(code *)&LAB_40185247_1)(param_2);
    if (param_3 == 1) {
      return;
    }
    if (param_3 != 2) goto LAB_40102e38;
    bVar1 = true;
  }
  else {
    if (param_3 != 2) {
      return;
    }
    bVar1 = false;
  }
  if ((*(int *)(param_2 + 0x40) == *(int *)(param_1 + 0x54)) &&
     (iVar2 = (*(code *)&SUB_4008b33c)(param_2,param_1 + 0x14), iVar2 == 0)) {
    (*(code *)&LAB_40185247_1)(param_2);
  }
  else if (!bVar1) {
    return;
  }
LAB_40102e38:
  (*(code *)&SUB_4008b530)(param_2,0,0x40);
  FUN_401054d0(param_2,1);
  return;
}

