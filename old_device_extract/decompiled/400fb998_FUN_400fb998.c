// Function : FUN_400fb998
// Address  : 0x400fb998
// Size     : 266 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400fb998(int param_1,undefined1 param_2,uint param_3,undefined4 param_4,int param_5,
                uint param_6,undefined1 param_7,undefined1 param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_68;
  undefined1 auStack_64 [2];
  byte bStack_62;
  ushort auStack_4c [2];
  int iStack_48;
  undefined1 auStack_44 [32];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  local_68 = 0;
  iVar3 = 0x110b;
  if (*(int *)(param_1 + 0xc) != 0) {
    memw();
    iVar1 = FUN_400fb6ac(param_1,param_2,param_3 & 0xff,param_4,&local_68,auStack_64,param_7,param_8
                        );
    iVar3 = iVar1;
    if (iVar1 == 0) {
      iVar2 = FUN_40184a1c(param_3 & 0xff);
      if (iVar2 == 0) {
        if ((param_3 & 0xf) == param_6) {
          iVar1 = (*(code *)&SUB_4008b33c)(param_5,auStack_4c);
          if (iVar1 != 0) {
            iVar3 = 0x1118;
          }
        }
        else {
          iVar3 = 0x1103;
        }
      }
      else {
        uVar5 = (uint)auStack_4c[0];
        iVar2 = param_5;
        uVar4 = local_68;
        if (param_6 < uVar5) {
          iVar3 = 0x110c;
        }
        else {
          while( true ) {
            uVar4 = uVar4 + 1;
            if (bStack_62 + local_68 <= uVar4) goto LAB_400fba80;
            memw();
            iVar3 = FUN_40184b50(param_1,uVar4,auStack_44);
            if (iVar3 != 0) goto LAB_400fba66;
            uVar6 = 0x20;
            if (uVar5 < 0x20) {
              uVar6 = uVar5;
            }
            memw();
            iVar3 = (*(code *)&SUB_4008b33c)(iVar2,auStack_44,uVar6);
            if (iVar3 != 0) break;
            uVar5 = uVar5 - uVar6;
            iVar2 = iVar2 + uVar6;
          }
          iVar3 = 0x1118;
        }
      }
    }
  }
LAB_400fba66:
  while( true ) {
    iVar1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
LAB_400fba80:
    iVar2 = FUN_400fc5c8(param_5,auStack_4c[0]);
    iVar3 = iVar1;
    if (iStack_48 != iVar2) {
      iVar3 = 0x1102;
    }
  }
  return iVar3;
}

