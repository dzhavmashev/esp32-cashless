// Function : FUN_400f3190
// Address  : 0x400f3190
// Size     : 449 bytes


int FUN_400f3190(undefined4 param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined **ppuVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  iVar3 = (*(code *)&SUB_400637f4)(param_1,param_2,param_1,param_2);
  ppuVar9 = &PTR_LAB_3f40a584;
  if (iVar3 == 0) {
    iVar3 = (*(code *)&SUB_400637f4)(param_1,param_2 & 0x7fffffff,0xffffffff,0x7fefffff);
    if ((iVar3 != 0) ||
       (iVar3 = (*(code *)&SUB_40063704)(param_1,param_2 & 0x7fffffff,0xffffffff,0x7fefffff),
       iVar3 < 1)) {
      if (param_4 != 0) {
        param_3 = param_3 + (param_4 ^ 0xffffffff);
      }
      iVar3 = (*(code *)&SUB_40063790)(param_1,param_2,0,0);
      if (iVar3 < 0) {
        param_3 = param_3 + -1;
        param_2 = param_2 ^ 0x80000000;
      }
      uVar13 = 0x4000000000000000;
      uVar6 = 0;
      while( true ) {
        uVar8 = (undefined4)((ulonglong)uVar13 >> 0x20);
        if (uVar6 == param_4) break;
        uVar6 = uVar6 + 1;
        uVar13 = (*(code *)&SUB_4006358c)((int)uVar13,uVar8,0,0x40240000);
      }
      uVar13 = (*(code *)&SUB_40002954)(0,0x3ff00000,(int)uVar13,uVar8);
      uVar12 = (*(code *)&SUB_40002590)
                         ((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),param_1,param_2);
      uVar8 = (undefined4)((ulonglong)uVar12 >> 0x20);
      iVar7 = 1;
      uVar13 = 0x3ff0000000000000;
      while( true ) {
        uVar11 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar10 = (undefined4)uVar13;
        uVar13 = (*(code *)&SUB_4006358c)(uVar10,uVar11,0,0x40240000);
        iVar4 = (*(code *)&SUB_40063704)
                          ((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,uVar8);
        if (0 < iVar4) break;
        iVar7 = iVar7 + 1;
      }
      uVar13 = (*(code *)&SUB_40002954)((int)uVar12,uVar8,uVar10,uVar11);
      param_3 = param_3 - iVar7;
      for (iVar4 = 0; 0 < param_3 - iVar4; iVar4 = iVar4 + 1) {
        *(undefined1 *)(param_5 + iVar4) = 0x20;
      }
      pbVar5 = (byte *)(param_5 + (uint)(-1 < param_3) * param_3);
      if (iVar3 < 0) {
        *pbVar5 = 0x2d;
        pbVar5 = pbVar5 + 1;
      }
      uVar6 = iVar7 + param_4;
      while( true ) {
        uVar8 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar6 = uVar6 - 1;
        if (uVar6 == 0xffffffff) break;
        cVar2 = (*(code *)&SUB_40002a78)((int)uVar13,uVar8);
        bVar1 = (cVar2 < '\t') * cVar2 + (cVar2 >= '\t') * '\t';
        *pbVar5 = bVar1 | 0x30;
        if ((param_4 == uVar6) && (param_4 != 0)) {
          pbVar5[1] = 0x2e;
          pbVar5 = pbVar5 + 2;
        }
        else {
          pbVar5 = pbVar5 + 1;
        }
        uVar12 = (*(code *)&SUB_4000c944)((int)(char)bVar1);
        uVar13 = (*(code *)&SUB_400026e4)
                           ((int)uVar13,uVar8,(int)uVar12,(int)((ulonglong)uVar12 >> 0x20));
        uVar13 = (*(code *)&SUB_4006358c)((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,0x40240000)
        ;
      }
      *pbVar5 = 0;
      return param_5;
    }
    ppuVar9 = (undefined **)0x3f40af54;
  }
  (*(code *)&SUB_4008bf10)(param_5,ppuVar9);
  return param_5;
}

