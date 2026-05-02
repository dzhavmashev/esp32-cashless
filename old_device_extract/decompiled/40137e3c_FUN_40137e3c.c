// Function : FUN_40137e3c
// Address  : 0x40137e3c
// Size     : 276 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40137e3c(undefined1 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 uint *param_6)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int in_a14;
  uint in_t0;
  undefined8 uVar8;
  undefined1 auStack_64 [64];
  int iStack_24;
  
  puVar2 = (uint *)&DAT_3ffc5708;
  uVar4 = 0x102;
  uVar7 = 0xec;
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
LAB_40137e56:
  uVar4 = uVar4 - 1;
  uVar3 = in_t0;
  if (uVar4 == 0) {
    uVar1 = 0;
    goto LAB_40137efe;
  }
  if (*(int *)(param_1 + 0xe0) == 0) {
    uVar1 = 0;
    goto LAB_40137efe;
  }
  memw();
  uVar1 = FUN_40137d94(param_1);
  uVar3 = in_t0;
  if (uVar1 != 0) goto LAB_40137efe;
  puVar2 = (uint *)(param_1 + uVar7);
  in_a14 = *(int *)(param_1 + 0xe0);
  uVar6 = 1;
  uVar3 = 0;
  iVar5 = 0;
  param_6 = puVar2;
  do {
    uVar8 = CONCAT44(uVar6,iVar5);
    if (in_a14 <= iVar5) {
      if ((((uVar6 ^ 1) & 1) != 0) || (uVar3 < 0x40)) goto LAB_40137e56;
      (*(code *)&SUB_4008b530)(auStack_64,0,0x40);
      param_6 = (uint *)(param_1 + 8);
      uVar1 = FUN_40140b04(param_6,auStack_64);
      uVar3 = in_t0;
      if (uVar1 == 0) {
        FUN_401409a0(param_6);
        FUN_4014098c(param_6);
        uVar1 = FUN_40140a08(param_6,0);
        uVar3 = in_t0;
        if (((uVar1 == 0) &&
            (uVar1 = FUN_40140aec(param_6,auStack_64,0x40), uVar3 = in_t0, uVar1 == 0)) &&
           (uVar7 = uVar1, uVar1 = FUN_4013cbd8(auStack_64,0x40), uVar3 = in_t0, uVar1 == 0)) {
          param_6 = *(uint **)(param_1 + 0xe0);
          iVar5 = 0;
          while (iVar5 < (int)param_6) {
            *puVar2 = 0;
            iVar5 = iVar5 + 1;
            puVar2 = puVar2 + 5;
            memw();
          }
          (*(code *)&SUB_4008b3d0)(param_2,auStack_64,param_3);
          uVar3 = in_t0;
        }
      }
LAB_40137efe:
      FUN_4013ae54(auStack_64,0x40);
      param_3 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      uVar8 = (*(code *)&SUB_40082ec4)();
      param_1 = &DAT_3ffc5708;
      uVar4 = uVar3;
      in_t0 = uVar3;
    }
    uVar6 = (uint)((ulonglong)uVar8 >> 0x20);
    if (*param_6 < param_6[1]) {
      uVar6 = uVar1;
    }
    if (param_6[2] == 1) {
      uVar3 = uVar3 + *param_6;
    }
    iVar5 = (int)uVar8 + 1;
    param_6 = param_6 + 5;
  } while( true );
}

