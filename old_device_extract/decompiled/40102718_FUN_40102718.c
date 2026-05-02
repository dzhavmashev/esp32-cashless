// Function : FUN_40102718
// Address  : 0x40102718
// Size     : 276 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_40102718(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,uint *param_5)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [8];
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b3d0)(&uStack_3c,param_4,8);
  puVar5 = (uint *)(param_3 * 8);
  (*(code *)&SUB_4008b3d0)(param_5,param_4 + 8,puVar5);
  iVar2 = FUN_401021e4(param_1,param_2);
  if (iVar2 == 0) goto LAB_40102825;
  param_5 = (uint *)((int)param_5 + (int)(puVar5 + -2));
  uVar4 = param_3 * 5;
  iVar3 = 6;
  param_4 = param_3;
  puVar1 = param_5;
LAB_40102767:
  puVar5 = puVar1;
  if ((int)param_4 < 1) goto code_r0x4010276a;
  goto LAB_401027ad;
code_r0x4010276a:
  iVar3 = iVar3 + -1;
  uVar4 = uVar4 - param_3;
  param_4 = param_3;
  puVar1 = param_5;
  if (iVar3 == 0) {
    FUN_40102230(iVar2);
    param_5 = &uStack_3c;
    param_4 = uStack_3c & 0xff;
    if (param_4 == 0xa6) {
      iVar3 = 0;
    }
    else {
LAB_40102825:
      iVar3 = -1;
    }
    param_3 = uStack_24;
    uVar4 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
LAB_401027ad:
    uStack_34 = uStack_3c;
    iVar6 = param_4 + uVar4;
    uStack_30 = CONCAT31(CONCAT21(CONCAT11((byte)iVar6 ^ (byte)((uint)local_38 >> 0x18),
                                           (byte)((uint)iVar6 >> 8) ^ (byte)((uint)local_38 >> 0x10)
                                          ),
                                  (byte)((uint)iVar6 >> 0x10) ^ (byte)((uint)local_38 >> 8)),
                         (byte)((uint)iVar6 >> 0x18) ^ (byte)local_38);
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_2c,puVar5,8);
    FUN_40102218(iVar2,&uStack_34);
    uStack_3c = uStack_34;
    local_38 = uStack_30;
    memw();
    (*(code *)&SUB_4008b3d0)(puVar5,auStack_2c,8);
    param_4 = param_4 - 1;
    puVar1 = puVar5 + -2;
  }
  goto LAB_40102767;
}

