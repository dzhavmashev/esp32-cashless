// Function : FUN_40151c80
// Address  : 0x40151c80
// Size     : 302 bytes


void FUN_40151c80(int *param_1,int param_2,byte param_3,int param_4,byte *param_5,byte *param_6,
                 byte *param_7)

{
  short sVar1;
  byte *pbVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    memw();
    FUN_40147fe4(1,0x800,1,"",&PTR_LAB_3f423ddc,0x4bc);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar3 = *param_1;
  if (iVar3 == 0) {
    FUN_40147fe4(1,0x800,1,"",&PTR_LAB_3f423ddc,0x4bd);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  pbVar2 = *(byte **)(*(int *)(param_2 + 4) + 4);
  *pbVar2 = param_3;
  memw();
  if ((param_3 & 0xc) == 8) {
    iVar3 = *(int *)(iVar3 + 0x14c);
    if (iVar3 == 0) {
      pbVar2[1] = 1;
      memw();
      memw();
      (*(code *)&SUB_4008b3d0)(pbVar2 + 4,param_7,6);
      (*(code *)&SUB_4008b3d0)(pbVar2 + 10,param_5,6);
      param_7 = param_6;
    }
    else {
      if (iVar3 != 1) {
        memw();
        goto LAB_40151d74;
      }
      pbVar2[1] = 2;
      memw();
      memw();
      (*(code *)&SUB_4008b3d0)(pbVar2 + 4,param_6,6);
      (*(code *)&SUB_4008b3d0)(pbVar2 + 10,param_7,6);
      param_7 = param_5;
    }
  }
  else {
    pbVar2[1] = 0;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(pbVar2 + 4,param_6,6);
    (*(code *)&SUB_4008b3d0)(pbVar2 + 10,param_5,6);
  }
  (*(code *)&SUB_4008b3d0)(pbVar2 + 0x10,param_7,6);
LAB_40151d74:
  pbVar2[2] = 0;
  pbVar2[3] = 0;
  memw();
  sVar1 = *(short *)((int)param_1 + param_4 * 2 + 0xae);
  *(short *)((int)param_1 + param_4 * 2 + 0xae) = sVar1 + 1;
  *(short *)(pbVar2 + 0x16) = sVar1 << 4;
  memw();
  if ((*param_6 & 1) != 0) {
    **(uint **)(param_2 + 0x2c) = **(uint **)(param_2 + 0x2c) | 2;
    **(uint **)(param_2 + 0x2c) = **(uint **)(param_2 + 0x2c) | 0x400;
  }
  memw();
  return;
}

