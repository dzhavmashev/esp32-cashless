// Function : FUN_4012d910
// Address  : 0x4012d910
// Size     : 84 bytes


bool FUN_4012d910(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x18) <= param_4)) &&
      (param_3 <= *(int *)(param_1 + 0x20))) &&
     ((*(char *)(*param_2 + 5) != '\x01' || ((*(byte *)(param_1 + 0x24) & 4) == 0)))) {
    iVar1 = FUN_40185b88();
    if (iVar1 == 0) {
      return false;
    }
    iVar1 = *param_2;
    if (((*(int *)(iVar1 + 0xd4) != 0) && (*(int *)(iVar1 + 0xd8) != 0)) &&
       (*(int *)(iVar1 + 0xcc) != 0)) {
      return *(int *)(iVar1 + 0xd0) == 0;
    }
  }
  return true;
}

