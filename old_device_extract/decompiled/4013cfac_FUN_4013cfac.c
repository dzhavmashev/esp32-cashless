// Function : FUN_4013cfac
// Address  : 0x4013cfac
// Size     : 298 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013cfac(undefined1 *param_1,int param_2,uint param_3,uint *param_4,uint *param_5,
                uint *param_6)

{
  undefined1 uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  iVar4 = -0x22;
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if ((param_3 & 0xf) == 0) {
    memw();
    iVar2 = FUN_401866a8(param_1);
    iVar4 = -0x20;
    if (iVar2 != 0) {
      func_0x4013cf40();
      memw();
      param_1[1] = 0;
      memw();
      uVar1 = FUN_401687e8(param_1 + 2,*param_1,param_2);
      puVar3 = (uint *)((int)param_6 + param_3);
      memw();
      param_1[1] = uVar1;
      if (param_2 == 0) {
        for (; param_6 != puVar3; param_6 = param_6 + 4) {
          (*(code *)&SUB_4008b3d0)(auStack_34,param_5,0x10);
          iVar4 = FUN_4013cee0(param_1,param_5,param_6);
          if (iVar4 != 0) goto LAB_4013d0b0;
          param_5 = param_5 + 4;
          *param_6 = *param_6 ^ *param_4;
          param_6[1] = param_6[1] ^ param_4[1];
          param_6[2] = param_6[2] ^ param_4[2];
          param_6[3] = param_6[3] ^ param_4[3];
          memw();
          (*(code *)&SUB_4008b3d0)(param_4,auStack_34,0x10);
        }
      }
      else {
        for (; param_6 != puVar3; param_6 = param_6 + 4) {
          *param_6 = *param_5 ^ *param_4;
          param_6[1] = param_5[1] ^ param_4[1];
          param_6[2] = param_5[2] ^ param_4[2];
          param_6[3] = param_5[3] ^ param_4[3];
          memw();
          iVar4 = FUN_4013cee0(param_1,param_6,param_6);
          if (iVar4 != 0) goto LAB_4013d0b0;
          (*(code *)&SUB_4008b3d0)(param_4,param_6,0x10);
          param_5 = param_5 + 4;
        }
      }
      iVar4 = 0;
LAB_4013d0b0:
      memw();
      FUN_4013cf58();
    }
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar4;
}

