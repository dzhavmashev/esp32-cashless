// Function : FUN_400e00e8
// Address  : 0x400e00e8
// Size     : 55 bytes


undefined1 FUN_400e00e8(undefined4 param_1,byte *param_2)

{
  char *pcVar1;
  byte bVar2;
  
  bVar2 = *param_2;
  pcVar1 = "expired";
  if (bVar2 == 1) {
    bVar2 = param_2[2];
    if (bVar2 < 0x28) {
      if (param_2[100] != 0) {
        return 1;
      }
      FUN_400f0780(0x3ffc5490,"er: %d\n");
      return 0;
    }
    pcVar1 = "d: %d)\n";
  }
  FUN_400f06a4(0x3ffc5490,pcVar1,bVar2);
  return 0;
}

