// Function : FUN_400d55c0
// Address  : 0x400d55c0
// Size     : 386 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d55c0(undefined4 ****param_1,undefined4 param_2,uint param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 ****ppppuVar3;
  undefined4 extraout_a3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 ****ppppuVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  char acStack_12a [226];
  uint uStack_48;
  uint uStack_44;
  ushort uStack_40;
  byte bStack_3e;
  char local_2b [7];
  undefined4 ***local_24 [9];
  
  ppppuVar3 = local_24;
  memw();
  memw();
  local_24[0] = _DAT_3ffc5708;
  iVar2 = (*(code *)&SUB_400636a8)(param_3,param_4,param_3,param_4);
  if (iVar2 == 0) goto LAB_400d5600;
LAB_400d55e5:
  FUN_400d4ac0(param_1,"PIO ISR null");
LAB_400d55ed:
  param_1 = _DAT_3ffc5708;
  memw();
  ppppuVar3 = (undefined4 ****)*ppppuVar3;
  memw();
  if (ppppuVar3 == _DAT_3ffc5708) {
    return;
  }
  func_0x40082ecc();
LAB_400d5600:
  iVar2 = (*(code *)&SUB_400636a8)(param_3,param_4,0,0);
  if (iVar2 != 0) {
    uVar10 = (*(code *)&SUB_40002590)(param_3,param_4,param_3,param_4);
    iVar2 = (*(code *)&SUB_400636a8)(param_3,param_4,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    if (iVar2 == 0) goto LAB_400d55e5;
  }
  uVar10 = (*(code *)&SUB_40063790)(param_3,param_4,0,0);
  uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
  if ((int)uVar10 < 0) {
    FUN_400d556c(param_1,0x2d);
    param_4 = param_4 ^ 0x80000000;
    uVar6 = extraout_a3;
  }
  FUN_400d46d0(&uStack_48,uVar6,param_3,param_4);
  uVar8 = uStack_48;
  ppppuVar7 = ppppuVar3;
  do {
    ppppuVar7 = (undefined4 ****)((int)ppppuVar7 + -1);
    param_4 = uVar8 % 10 + 0x30;
    *(char *)ppppuVar7 = (char)param_4;
    bVar1 = 9 < uVar8;
    uVar8 = uVar8 / 10;
  } while (bVar1);
  FUN_400d4aa0(param_1,ppppuVar7,(int)ppppuVar3 - (int)ppppuVar7);
  uVar8 = (uint)bStack_3e;
  if (uVar8 != 0) {
    uVar4 = uVar8;
    pcVar5 = local_2b + 1;
    uVar9 = uStack_44;
    while( true ) {
      pcVar5 = pcVar5 + -1;
      if ((char)(uVar4 - 1) == -1) break;
      uVar4 = uVar4 - 1 & 0xff;
      *pcVar5 = (char)uVar9 + (char)(uVar9 / 10) * -10 + '0';
      uVar9 = uVar9 / 10;
    }
    local_2b[-uVar8] = '.';
    FUN_400d4aa0(param_1,local_2b + 1 + (uVar8 ^ 0xffffffff),uVar8 + 1);
    param_4 = 0x2e;
  }
  param_3 = 0;
  if (uStack_40 != 0) {
    FUN_400d556c(param_1,0x65);
    uVar8 = (uint)uStack_40;
    if ((uStack_40 & 0x8000) != 0) {
      FUN_400d556c(param_1,0x2d);
      uVar8 = -uVar8;
    }
    uVar8 = uVar8 & 0xffff;
    ppppuVar7 = ppppuVar3;
    do {
      ppppuVar7 = (undefined4 ****)((int)ppppuVar7 + -1);
      param_3 = uVar8 / 10;
      param_4 = uVar8 % 10 + 0x30;
      *(char *)ppppuVar7 = (char)param_4;
      bVar1 = 9 < uVar8;
      uVar8 = param_3;
    } while (bVar1);
    FUN_400d4aa0(param_1,ppppuVar7,(int)ppppuVar3 - (int)ppppuVar7);
  }
  goto LAB_400d55ed;
}

