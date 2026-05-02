// Function : FUN_400de2fc
// Address  : 0x400de2fc
// Size     : 127 bytes


undefined4 FUN_400de2fc(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = *param_2;
  if (bVar1 == 5) {
    if ((param_2[0x7b] < 0x28) && (param_2[0x7c] < 0x28)) {
      if (0x122 < (ushort)(*(short *)(param_2 + 0x80) - 10U)) {
        FUN_400f06a4(0x3ffc5490,"X: %d)\n","de: %d\n");
        return 1;
      }
      return 1;
    }
    FUN_400f06a4(0x3ffc5490,"de: %s\n","de: %d\n");
    return 0;
  }
  pcVar2 = "t_based";
  if (bVar1 != 2) {
    if (bVar1 < 3) {
      pcVar2 = "ecovery";
      if ((bVar1 == 0) || (pcVar2 = "", bVar1 == 1)) goto LAB_400de32d;
    }
    else {
      pcVar2 = "r_based";
      if ((bVar1 == 3) || (pcVar2 = "h_relay", bVar1 == 4)) goto LAB_400de32d;
    }
    pcVar2 = " OID is unknown";
  }
LAB_400de32d:
  FUN_400f06a4(0x3ffc5490,"topped\n","de: %d\n",pcVar2);
  return 0;
}

