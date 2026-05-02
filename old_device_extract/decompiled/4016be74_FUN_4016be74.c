// Function : FUN_4016be74
// Address  : 0x4016be74
// Size     : 391 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016be74(byte param_1,short param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  short local_50;
  short asStack_4e [7];
  int iStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  uint uStack_2c;
  
  uStack_34 = (uint)param_1;
  bVar5 = 0;
  iStack_40 = (int)param_2;
  iStack_30 = (uint)(-1 < (char)(param_1 - 0xc)) * (int)(char)(param_1 - 0xc);
  uStack_3c = param_4 & 0xff;
  uVar3 = 0;
  bVar1 = 0;
  uStack_38 = 0;
  uStack_2c = 0;
  do {
    if (bVar5 < 4) {
      bVar1 = (**(code **)(_DAT_3ffc7e64 + 0x128))((int)(char)bVar1,1);
      uVar3 = (**(code **)(_DAT_3ffc7e64 + 0x128))((int)(char)uVar3,0);
      uVar3 = uVar3 & 0xff;
    }
    bVar2 = (byte)uVar3;
    (**(code **)(_DAT_3ffc7e64 + 0x138))(1,iStack_30,iStack_40,asStack_4e,&local_50,uStack_3c);
    iVar7 = (int)local_50;
    iVar4 = (int)asStack_4e[0];
    iVar6 = (uint)(iVar7 < iVar4) * iVar7 + (uint)(iVar7 >= iVar4) * iVar4;
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    *param_3 = (byte)(((iVar7 - iVar4) * 0x800) / iVar6 + 0x10 >> 5);
    memw();
    (**(code **)(_DAT_3ffc7e64 + 0x138))(0,uStack_34,iStack_40,asStack_4e,&local_50,uStack_3c);
    iVar4 = (int)(short)(asStack_4e[0] + local_50);
    if (iVar4 == 0) {
      iVar4 = 1;
    }
    iVar4 = (((int)asStack_4e[0] - (int)local_50) * 0x1000) / iVar4 + 0x10 >> 5;
    param_3[1] = (byte)iVar4;
    memw();
    if (bVar5 < 3) {
      uVar3 = uVar3 - iVar4 & 0xff;
      bVar1 = bVar1 - *param_3;
    }
    else {
      uStack_38 = iVar4 + uStack_38 & 0xff;
      uStack_2c = *param_3 + uStack_2c & 0xff;
      iVar4 = (**(code **)(_DAT_3ffc7e64 + 0x140))((int)(char)*param_3);
      if ((iVar4 < 2) &&
         (iVar4 = (**(code **)(_DAT_3ffc7e64 + 0x140))((int)(char)param_3[1]), iVar4 < 2))
      goto LAB_4016bfd4;
      if (bVar5 == 6) {
        bVar1 = bVar1 - (char)((char)uStack_2c + 2 >> 2);
        bVar2 = bVar2 - (char)((char)uStack_38 + 2 >> 2);
        goto LAB_4016bfd4;
      }
    }
    bVar2 = (byte)uVar3;
    bVar5 = bVar5 + 1;
    if (bVar5 == 7) {
LAB_4016bfd4:
      (**(code **)(_DAT_3ffc7e64 + 0x128))((int)(char)bVar1,1);
      (**(code **)(_DAT_3ffc7e64 + 0x128))((int)(char)bVar2,0);
      *param_3 = bVar1;
      param_3[1] = bVar2;
      memw();
      return;
    }
  } while( true );
}

