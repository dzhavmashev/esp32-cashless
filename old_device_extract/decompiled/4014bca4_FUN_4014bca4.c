// Function : FUN_4014bca4
// Address  : 0x4014bca4
// Size     : 137 bytes


void FUN_4014bca4(int param_1,char *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x7d9);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (*param_2 == -0x23) {
    param_2 = param_2 + 4;
  }
  bVar1 = *(byte *)(param_1 + 0x163);
  uVar2 = 0;
  if (bVar1 != 0) {
    do {
      if (((uint)(byte)param_2[((int)uVar2 >> 3) + 8] & 1 << ((byte)uVar2 & 7)) != 0) {
        pbVar3 = (byte *)(param_1 + 0x164);
        for (iVar4 = 0; iVar4 < (int)(uint)bVar1; iVar4 = iVar4 + 1) {
          if ((*pbVar3 & 0x7f) == uVar2) {
            *pbVar3 = *pbVar3 | 0x80;
            memw();
          }
          pbVar3 = pbVar3 + 1;
        }
        memw();
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 0x7f);
    return;
  }
  FUN_40147fe4(1,0x20,2,0x3f4365dd);
  return;
}

