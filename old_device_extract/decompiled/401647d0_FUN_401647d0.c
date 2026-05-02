// Function : FUN_401647d0
// Address  : 0x401647d0
// Size     : 129 bytes


void FUN_401647d0(int param_1,uint *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  
  if (((*param_2 >> 0x16 & 1) == 0) && (param_1 != 0)) {
    uVar4 = *(byte *)(param_1 + 0xb) & 3;
    if ((*(byte *)(param_1 + 0xb) & 3) != 0) {
      if ((*param_2 & 8) == 0) {
        uVar1 = *(undefined1 *)(param_1 + 9);
      }
      else {
        uVar1 = *(undefined1 *)(param_1 + 8);
      }
LAB_4016483d:
      *(undefined1 *)(param_2 + 3) = uVar1;
      memw();
      memw();
      return;
    }
    uVar7 = param_2[7];
    if (uVar7 == 0) {
      memw();
      FUN_40147fe4(6,0x800,1,"is null",&DAT_3f42470c,"ryLimit",0x5b9);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar2 = (uint)*(byte *)((int)param_2 + 6);
    pbVar6 = (byte *)(uVar7 + 1);
    uVar8 = (uint)*(byte *)((int)param_2 + 5);
    iVar3 = 4;
    uVar5 = uVar4;
    do {
      uVar5 = uVar5 + *pbVar6 & 0xff;
      if ((uVar8 < uVar2) * uVar2 + (uVar8 >= uVar2) * uVar8 < uVar5) {
        uVar1 = *(undefined1 *)(uVar4 * 2 + uVar7);
        goto LAB_4016483d;
      }
      uVar4 = uVar4 + 1;
      pbVar6 = pbVar6 + 2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

