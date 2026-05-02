// Function : FUN_400d9e14
// Address  : 0x400d9e14
// Size     : 21 bytes


void FUN_400d9e14(undefined4 param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = "nnected";
  if (*(char *)(param_2 + 0x10) == '\0') {
    pcVar1 = "0.0.0.1";
  }
  FUN_400f0be8(param_1,pcVar1);
  return;
}

