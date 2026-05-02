// Function : FUN_40184edc
// Address  : 0x40184edc
// Size     : 23 bytes


bool FUN_40184edc(int *param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (*param_1 != 0) {
    bVar1 = param_1[1] != 0;
  }
  return bVar1;
}

