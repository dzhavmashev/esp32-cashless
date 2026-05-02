// Function : FUN_40136090
// Address  : 0x40136090
// Size     : 70 bytes


undefined4 FUN_40136090(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  
  if (2 < param_3) {
    pcVar3 = (char *)*param_2;
    *param_2 = pcVar3 + 1;
    if (*pcVar3 == '\x03') {
      *param_2 = pcVar3 + 2;
      cVar1 = pcVar3[1];
      *param_2 = pcVar3 + 3;
      memw();
      puVar2 = (undefined4 *)FUN_40135610(CONCAT11(cVar1,pcVar3[2]));
      if (puVar2 == (undefined4 *)0x0) {
        return 0xffffb180;
      }
      *param_1 = *puVar2;
      memw();
      return 0;
    }
  }
  return 0xffffb080;
}

