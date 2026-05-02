// Function : FUN_400d46d0
// Address  : 0x400d46d0
// Size     : 486 bytes


void FUN_400d46d0(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  
  uVar12 = CONCAT44(param_4,param_3);
  *(undefined1 *)((int)param_1 + 10) = 9;
  iVar1 = (*(code *)&SUB_40063768)(param_3,param_4,0,0x416312d0);
  if (iVar1 < 0) {
    iVar1 = 0x100;
    iVar7 = 8;
    sVar5 = 0;
  }
  else {
    iVar7 = 8;
    sVar5 = 0;
    iVar1 = 0x100;
    do {
      uVar6 = (undefined4)((ulonglong)uVar12 >> 0x20);
      uVar11 = FUN_400d3e5c(&DAT_3f4021c0,iVar7);
      iVar2 = (*(code *)&SUB_40063704)
                        ((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,uVar6);
      if (iVar2 < 1) {
        uVar11 = FUN_400d3e5c("s:%d\n",iVar7);
        uVar12 = (*(code *)&SUB_4006358c)
                           ((int)uVar12,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
        sVar5 = (short)iVar1 + sVar5;
      }
      iVar7 = iVar7 + -1;
      iVar1 = iVar1 >> 1;
    } while (iVar7 != -1);
    iVar7 = 0xff;
  }
  uVar6 = (undefined4)((ulonglong)uVar12 >> 0x20);
  iVar2 = (*(code *)&SUB_400636dc)((int)uVar12,uVar6,0,0);
  if ((0 < iVar2) &&
     (iVar2 = (*(code *)&SUB_40063704)((int)uVar12,uVar6,0x88e368f1,0x3ee4f8b5), iVar2 < 1)) {
    iVar2 = 0;
    while( true ) {
      uVar6 = (undefined4)((ulonglong)uVar12 >> 0x20);
      if ((iVar7 - iVar2 & 0x80U) != 0) break;
      iVar9 = (char)iVar7 - iVar2;
      uVar11 = FUN_400d3e5c("s:%d\n",iVar9);
      uVar11 = (*(code *)&SUB_4006358c)((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,0x40240000);
      iVar3 = (*(code *)&SUB_400636dc)
                        ((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,uVar6);
      if (0 < iVar3) {
        uVar11 = FUN_400d3e5c(&DAT_3f4021c0,iVar9);
        uVar12 = (*(code *)&SUB_4006358c)
                           ((int)uVar12,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
        sVar5 = sVar5 - (short)iVar1;
      }
      iVar1 = iVar1 >> 1;
      iVar2 = iVar2 + 1;
    }
  }
  uVar6 = (undefined4)((ulonglong)uVar12 >> 0x20);
  *(short *)(param_1 + 2) = sVar5;
  uVar4 = (*(code *)&SUB_40002b30)((int)uVar12,uVar6);
  uVar8 = 1000000000;
  *param_1 = uVar4;
  for (uVar10 = uVar4; 9 < uVar10; uVar10 = uVar10 / 10) {
    uVar8 = uVar8 / 10;
    *(char *)((int)param_1 + 10) = *(char *)((int)param_1 + 10) + -1;
  }
  uVar11 = (*(code *)&SUB_4000c938)(uVar4);
  uVar12 = (*(code *)&SUB_400026e4)((int)uVar12,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
  uVar11 = (*(code *)&SUB_4000c938)(uVar8);
  uVar12 = (*(code *)&SUB_4006358c)
                     ((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,
                      (int)((ulonglong)uVar11 >> 0x20));
  iVar1 = (*(code *)&SUB_40002b30)();
  uVar11 = (*(code *)&SUB_4000c938)();
  uVar12 = (*(code *)&SUB_400026e4)
                     ((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,
                      (int)((ulonglong)uVar11 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar12 >> 0x20);
  (*(code *)&SUB_40002590)((int)uVar12,uVar6,(int)uVar12,uVar6);
  iVar7 = (*(code *)&SUB_40002b30)();
  if ((uint)(iVar7 + iVar1) < uVar8) {
    param_1[1] = iVar7 + iVar1;
  }
  else {
    param_1[1] = 0;
    *param_1 = uVar4 + 1;
    if ((sVar5 != 0) && (9 < uVar4 + 1)) {
      *(short *)(param_1 + 2) = sVar5 + 1;
      *param_1 = 1;
    }
  }
  while ((uVar10 = param_1[1] / 10, param_1[1] == uVar10 * 10 &&
         ('\0' < *(char *)((int)param_1 + 10)))) {
    param_1[1] = uVar10;
    *(char *)((int)param_1 + 10) = *(char *)((int)param_1 + 10) + -1;
  }
  return;
}

