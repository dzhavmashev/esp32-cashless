// Function : FUN_40118ff0
// Address  : 0x40118ff0
// Size     : 64 bytes


void FUN_40118ff0(int param_1,char param_2)

{
  FUN_4010b840(param_1,(int)param_2,0x40);
  if (param_2 == '\0') {
    if ((*(char *)(param_1 + 0x95) != '\0') && (*(int *)(param_1 + 0x9c) != 0)) {
      FUN_4010b840(param_1,1,0x40);
    }
    if ((*(char *)(param_1 + 0x96) != '\0') && (*(int *)(param_1 + 0xa0) != 0)) {
      FUN_4010b840(param_1,2,0x40);
    }
  }
  return;
}

