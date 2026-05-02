// Function : FUN_400e76c0
// Address  : 0x400e76c0
// Size     : 37 bytes


void FUN_400e76c0(undefined4 *param_1)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = "u sent\n";
  if (*(char *)(param_1 + 3) != '\0') {
    iVar1 = FUN_400da4f0(*param_1,"u sent\n");
    if (iVar1 != 0) {
      FUN_400e7630(param_1);
      return;
    }
    pcVar2 = "isabled";
  }
  FUN_400f0780(0x3ffc5490,pcVar2);
  return;
}

