// Function : FUN_4011c260
// Address  : 0x4011c260
// Size     : 204 bytes


char FUN_4011c260(uint *param_1,int param_2,ushort param_3,byte param_4,uint *param_5)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 in_t0;
  uint *apuStack_48 [2];
  int iStack_40;
  ushort uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  uint uStack_30;
  byte bStack_2c;
  undefined4 uStack_28;
  
  if (param_1 == (uint *)0x0) {
    return -0x10;
  }
  if ((*param_1 & 0xf0) == 0x10) {
    bVar1 = true;
    if (param_1[9] == 0) {
      bVar1 = (param_1[0xd] & 2) != 0 || (param_4 & 4) != 0;
    }
    if ((param_5 != (uint *)0x0) || (!bVar1)) {
      puVar6 = (uint *)(param_2 + 4);
      uVar3 = 0;
      for (iVar5 = 0; iVar5 < (int)(uint)param_3; iVar5 = iVar5 + 1) {
        uVar7 = *puVar6;
        puVar6 = puVar6 + 2;
        uVar3 = uVar3 + uVar7;
        if (uVar3 < uVar7) {
          return -6;
        }
      }
      if (uVar3 != 0) {
        if ((int)uVar3 < 0) {
          if (param_5 == (uint *)0x0) {
            return -6;
          }
          uVar3 = 0x7fffffff;
        }
        uStack_38 = 0;
        memw();
        uStack_30 = 0;
        uVar4 = 0;
        apuStack_48[0] = param_1;
        iStack_40 = param_2;
        uStack_3c = param_3;
        uStack_34 = uVar3;
        bStack_2c = param_4;
        if (param_1[9] == 0) goto LAB_4011c319;
        memw();
        uStack_28 = FUN_4011b010();
        while( true ) {
          uVar4 = in_t0;
          memw();
          cVar2 = FUN_4011bff4(&DAT_4011d694,apuStack_48);
          if (cVar2 != '\0') {
            return cVar2;
          }
          if (param_5 != (uint *)0x0) {
            *param_5 = uStack_30;
          }
          if ((bVar1) || (uStack_30 == uVar3)) break;
          memw();
          (*(code *)&SUB_40094c54)("ing pcb",0x43d,"l bytes","t exist");
          in_t0 = uVar4;
LAB_4011c319:
          memw();
          uStack_28 = uVar4;
        }
      }
      return '\0';
    }
  }
  return -6;
}

