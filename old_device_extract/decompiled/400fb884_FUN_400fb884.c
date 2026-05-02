// Function : FUN_400fb884
// Address  : 0x400fb884
// Size     : 272 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fb884(uint *param_1,undefined1 param_2,uint param_3,undefined4 param_4,int param_5,
                 uint param_6,undefined1 param_7,undefined1 param_8)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint local_68;
  undefined1 auStack_64 [2];
  byte bStack_62;
  ushort auStack_4c [2];
  int iStack_48;
  undefined1 auStack_44 [32];
  uint *puStack_24;
  
  memw();
  puVar4 = &local_68;
  memw();
  puStack_24 = _DAT_3ffc5708;
  local_68 = 0;
  puVar3 = (uint *)0x110b;
  if (param_1[3] != 0) {
    memw();
    puVar1 = (uint *)FUN_400fb6ac(param_1,param_2,param_3 & 0xff,param_4,puVar4,auStack_64,param_7,
                                  param_8);
    puVar3 = puVar1;
    if (puVar1 == (uint *)0x0) {
      iVar2 = FUN_40184a1c(param_3 & 0xff);
      if (iVar2 != 0) goto LAB_400fb905;
      if ((param_3 & 0xf) == param_6) {
        (*(code *)&SUB_4008b3d0)(param_5,auStack_4c);
      }
      else {
        puVar3 = (uint *)0x1103;
      }
    }
  }
LAB_400fb8e9:
  do {
    while( true ) {
      param_1 = puVar3;
      puVar4 = puStack_24;
      puVar1 = _DAT_3ffc5708;
      memw();
      memw();
      if (puStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
LAB_400fb905:
      uVar5 = (uint)auStack_4c[0];
      if (uVar5 <= param_6) break;
      puVar3 = (uint *)0x110c;
    }
    param_6 = *puVar4;
    iVar2 = param_5;
    while (param_6 = param_6 + 1, param_6 < (uint)bStack_62 + *puVar4) {
      memw();
      puVar3 = (uint *)FUN_40184b50(param_1,param_6,auStack_44);
      if (puVar3 != (uint *)0x0) goto LAB_400fb8e9;
      uVar6 = 0x20;
      if (uVar5 < 0x20) {
        uVar6 = uVar5;
      }
      memw();
      iVar2 = (*(code *)&SUB_4008b3d0)(iVar2,auStack_44,uVar6);
      uVar5 = uVar5 - uVar6;
      iVar2 = iVar2 + uVar6;
    }
    iVar2 = FUN_400fc5c8(param_5,auStack_4c[0]);
    puVar3 = puVar1;
    if ((iStack_48 != iVar2) &&
       (puVar3 = (uint *)FUN_400fb554(param_1,*puVar4), puVar3 == (uint *)0x0)) {
      puVar3 = (uint *)0x1102;
    }
  } while( true );
}

