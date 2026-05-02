// Function : FUN_4014138c
// Address  : 0x4014138c
// Size     : 396 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014138c(int param_1,uint param_2,uint param_3,uint param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uStack_48;
  undefined1 auStack_44 [15];
  char acStack_35 [17];
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  uStack_48 = 0;
  memw();
  (*(code *)&SUB_4008b530)(auStack_44,0,0x10);
  (*(code *)&SUB_4008b530)(acStack_35 + 1,0,0x10);
  if (param_1 != 0) goto LAB_401413f6;
  uVar2 = (*(code *)&SUB_40094b80)();
  pcVar6 = "pplied\n";
LAB_401413d3:
  do {
    FUN_4012113c(1,&DAT_3f422a60,pcVar6,uVar2,&DAT_3f422a60);
    iVar3 = -1;
    while( true ) {
      param_1 = iVar3;
      param_3 = uStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (uStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
LAB_401413f6:
      if (param_3 == 0) {
        uVar2 = (*(code *)&SUB_40094b80)();
        pcVar6 = "pplied\n";
        goto LAB_401413d3;
      }
      if (param_4 == 0) break;
      if ((param_4 <= param_3) || (iVar3 = -0x14, param_2 <= param_4 - param_3)) {
        if (*(int *)(param_1 + 0x180) == 1) {
          memw();
          (*(code *)&SUB_4008b3d0)(auStack_44,param_1 + 0x20,0x10);
          puVar4 = auStack_44;
          uVar5 = 0x10;
          do {
            uVar5 = uVar5 - 1;
            cVar1 = puVar4[0xf];
            puVar4[0xf] = cVar1 + '\x01';
            memw();
            puVar4 = puVar4 + -1;
          } while ((char)(cVar1 + '\x01') == '\0' && 0xc < uVar5);
          memw();
          (*(code *)&SUB_4008b3d0)(param_1 + 0x20,auStack_44,0x10);
          *(undefined4 *)(param_1 + 0x180) = 2;
        }
        else if (*(int *)(param_1 + 0x180) == 2) {
          (*(code *)&SUB_4008b3d0)(auStack_44,param_1 + 0x20,0x10);
        }
        if (*(int *)(param_1 + 0x154) == 0) {
          memw();
          FUN_40140fa8(param_1,param_3,param_2,param_1 + 0x10);
        }
        memw();
        iVar3 = FUN_4013d1b0(param_1 + 0x15c,param_2,&uStack_48,auStack_44,acStack_35 + 1,param_3,
                             param_4);
        if (iVar3 == 0) {
          (*(code *)&SUB_4008b3d0)(param_1 + 0x20,auStack_44,0x10);
          *(uint *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + param_2;
          if (*(int *)(param_1 + 0x154) == 1) {
            memw();
            FUN_40140fa8(param_1,param_4,param_2,param_1 + 0x10);
          }
        }
      }
    }
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar6 = "pplied\n";
  } while( true );
}

