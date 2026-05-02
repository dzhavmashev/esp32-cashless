// Function : FUN_40147c10
// Address  : 0x40147c10
// Size     : 148 bytes


int FUN_40147c10(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"id MMIE",&DAT_3f4239c1,0x95);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((uint)*(ushort *)(param_2 + 0x16) + (uint)*(ushort *)(param_2 + 0x14) < 0x20) {
    return 0;
  }
  iVar4 = *(int *)(*(int *)(param_2 + 4) + 4);
  if ((*(byte *)(iVar4 + 4) & 1) == 0) {
    uVar2 = (uint)*(byte *)(param_1 + 0x134);
  }
  else {
    pbVar5 = (byte *)(iVar4 + param_3);
    bVar1 = pbVar5[3];
    if ((bVar1 & 0x20) == 0) {
      if (*(char *)(param_1 + 0x28b) != '\b') {
        uVar2 = (uint)*(byte *)(param_1 + 0x135);
        goto LAB_40147c8e;
      }
    }
    else if (*(char *)(param_1 + 0x28b) != '\b') {
      uVar2 = (uint)*(byte *)(param_1 + (uint)(bVar1 >> 6) + 0x137);
      if (uVar2 == 0xff) {
        return 0;
      }
      goto LAB_40147c8e;
    }
    uVar2 = (uint)*pbVar5;
  }
LAB_40147c8e:
  iVar4 = *(int *)(&DAT_3ffc8930 + uVar2 * 4);
  if (iVar4 != 0) {
    iVar3 = (**(code **)(*(int *)(iVar4 + 0xa0) + 0x14))(iVar4,param_2,param_3);
    if (iVar3 != 0) {
      return iVar4;
    }
  }
  return 0;
}

