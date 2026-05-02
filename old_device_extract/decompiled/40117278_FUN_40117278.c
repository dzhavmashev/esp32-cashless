// Function : FUN_40117278
// Address  : 0x40117278
// Size     : 89 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40117278(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  
  if ((*(byte *)(param_1 + 0xeb) & 1) != 0) {
    pbVar1 = (byte *)(param_1 + 0x4c);
    pbVar2 = (byte *)(param_1 + 0x94);
    do {
      if (((((*pbVar2 & 0x10) != 0) && (_DAT_3ffc83e4 == *(int *)pbVar1)) &&
          (_DAT_3ffc83e8 == *(int *)(pbVar1 + 4))) &&
         (((_DAT_3ffc83ec == *(int *)(pbVar1 + 8) && (_DAT_3ffc83f0 == *(int *)(pbVar1 + 0xc))) &&
          (pbVar1[0x10] == DAT_3ffc83f4)))) {
        return 1;
      }
      pbVar1 = pbVar1 + 0x18;
      pbVar2 = pbVar2 + 1;
    } while (pbVar1 != (byte *)(param_1 + 0x94));
  }
  return 0;
}

