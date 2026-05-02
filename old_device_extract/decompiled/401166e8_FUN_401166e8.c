// Function : FUN_401166e8
// Address  : 0x401166e8
// Size     : 54 bytes


byte FUN_401166e8(uint *param_1,uint *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  byte bVar3;
  uint uVar4;
  
  puVar2 = (undefined4 *)&DAT_3ffc83fc;
  while( true ) {
    do {
      puVar2 = (undefined4 *)*puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        return 0;
      }
    } while ((((*(byte *)((int)puVar2 + 0xeb) & 1) == 0) ||
             (bVar1 = *(byte *)((int)puVar2 + 0xeb) >> 2, bVar3 = bVar1 & 1, (bVar1 & 1) == 0)) ||
            (uVar4 = puVar2[1], uVar4 == 0));
    if (((uVar4 ^ *param_1) & puVar2[7]) == 0) break;
    if (((uVar4 ^ *param_2) & puVar2[7]) == 0) {
      return bVar3;
    }
  }
  return bVar3;
}

