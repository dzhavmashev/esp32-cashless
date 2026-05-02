// Function : FUN_400e4bd8
// Address  : 0x400e4bd8
// Size     : 55 bytes


void FUN_400e4bd8(uint *param_1,char param_2)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = " -> %d\n";
  if ((*param_1 & 0xfffffffd) == 0) {
    if ((param_2 != '\0') || (iVar1 = FUN_400f1a9c(), 59999 < iVar1 - param_1[0x7f])) {
      FUN_400e4b9c(param_1,1);
      return;
    }
    pcVar2 = "rogress";
  }
  FUN_400f0780(0x3ffc5490,pcVar2);
  return;
}

