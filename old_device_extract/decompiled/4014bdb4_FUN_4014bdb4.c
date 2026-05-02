// Function : FUN_4014bdb4
// Address  : 0x4014bdb4
// Size     : 308 bytes


undefined1 * FUN_4014bdb4(undefined1 *param_1,int *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  
  if ((param_2 == (int *)0x0) || (iVar2 = *param_2, iVar2 == 0)) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x8b1);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  (*(code *)&SUB_4008b530)(param_1,0,0x16);
  puVar1 = (undefined1 *)FUN_4015b1d4();
  *param_1 = *puVar1;
  memw();
  if ((*(uint *)(*param_2 + 0x158) & 0x20000000) == 0) {
    param_1[1] = 0;
    memw();
  }
  else {
    param_1[1] = 8;
    memw();
    memw();
  }
  if (*(char *)(iVar2 + 0x157) == '\x01') {
    if ((byte)(*(char *)(iVar2 + 0x156) - 1U) < 9) {
      param_1[1] = param_1[1] | 1;
      memw();
      memw();
    }
  }
  else if ((*(char *)(iVar2 + 0x157) == '\x02') && ((byte)(*(char *)(iVar2 + 0x156) - 5U) < 9)) {
    param_1[1] = param_1[1] | 3;
    memw();
  }
  if (*(char *)(iVar2 + 0x157) == '\x01') {
    bVar3 = *(char *)(iVar2 + 0x156) - 1;
    memw();
  }
  else {
    if (*(char *)(iVar2 + 0x157) != '\x02') goto LAB_4014be8c;
    bVar3 = *(char *)(iVar2 + 0x156) - 5;
  }
  if (bVar3 < 9) {
    param_1[1] = param_1[1] | 4;
    memw();
  }
LAB_4014be8c:
  param_1[2] = *(undefined1 *)(*param_2 + 0x1b8);
  memw();
  iVar6 = *param_2;
  iVar2 = 0;
  pbVar5 = (byte *)(iVar6 + 0x1ba);
  memw();
  for (; iVar2 < (int)(uint)*(byte *)(iVar6 + 0x1b9); iVar2 = iVar2 + 1) {
    bVar3 = *pbVar5;
    uVar4 = bVar3 & 0x7f;
    if ((uVar4 != 0x7f) && ((char)bVar3 < '\0')) {
      param_1[((int)uVar4 >> 3) + 6] =
           (byte)(1 << 0x20 - (0x20 - (bVar3 & 7))) | param_1[((int)uVar4 >> 3) + 6];
      memw();
    }
    pbVar5 = pbVar5 + 1;
  }
  memw();
  return param_1 + 0x16;
}

