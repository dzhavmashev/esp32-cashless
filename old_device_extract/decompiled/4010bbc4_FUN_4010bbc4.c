// Function : FUN_4010bbc4
// Address  : 0x4010bbc4
// Size     : 357 bytes


undefined4 *
FUN_4010bbc4(undefined4 *param_1,ushort param_2,uint param_3,undefined4 param_4,uint param_5,
            undefined4 *param_6)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  char *pcVar10;
  int in_t0;
  
  puVar3 = (undefined4 *)0x41;
  uVar2 = (uint)param_2;
  uVar5 = (uint)param_1 & 0xffff;
  if (param_3 != 0x41) {
    if (param_3 < 0x42) {
      if (param_3 == 1) goto LAB_4010bc4a;
    }
    else {
      if (param_3 == 0x182) {
        puVar3 = (undefined4 *)0x0;
        param_5 = 0xfffffffc;
        param_6 = (undefined4 *)0x0;
        goto LAB_4010bc61;
      }
      puVar3 = (undefined4 *)0x280;
      if (param_3 == 0x280) {
        uVar6 = uVar2 + 3 & 0xfffffffc;
        uVar2 = (uVar5 + 3 & 0xfffffffc) + uVar6 & 0xffff;
        if ((uVar6 <= uVar2 + 0x18) && (uVar6 <= uVar2)) {
          puVar3 = (undefined4 *)FUN_4010af90();
          if (puVar3 != (undefined4 *)0x0) {
            *puVar3 = 0;
            puVar3[1] = (int)puVar3 + ((uint)param_1 & 0xffff) + 0x1b & 0xfffffffc;
            *(ushort *)(puVar3 + 2) = param_2;
            *(ushort *)((int)puVar3 + 10) = param_2;
            memw();
            puVar3[3] = 0x10080;
            puVar3[4] = 0;
            puVar3[5] = 0;
            memw();
            return puVar3;
          }
          return (undefined4 *)0x0;
        }
        return (undefined4 *)0x0;
      }
    }
    pcVar10 = "IGNMENT";
    uVar9 = 299;
    iVar7 = in_t0;
    do {
      memw();
      (*(code *)&SUB_40094c54)("if_init",uVar9,"ference",pcVar10);
      puVar4 = puVar3;
      in_t0 = iVar7;
      do {
        puVar3 = param_1;
        if (puVar4 != (undefined4 *)0x0) {
          *param_6 = param_1;
          puVar3 = puVar4;
        }
        uVar2 = uVar2 - iVar7 & 0xffff;
        uVar5 = 0;
        param_6 = param_1;
        if (uVar2 == 0) {
          memw();
          return puVar3;
        }
LAB_4010bc61:
        param_1 = (undefined4 *)FUN_4010b058(0x11);
        if (param_1 == (undefined4 *)0x0) {
          FUN_4011b020();
          cVar1 = DAT_3ffc8404;
          memw();
          memw();
          DAT_3ffc8404 = 1;
          memw();
          FUN_4011b040();
          if ((cVar1 == '\0') && (cVar1 = FUN_40109db4(0x4010b98c,0), cVar1 != '\0')) {
            FUN_4011b020();
            memw();
            DAT_3ffc8404 = 0;
            memw();
            FUN_4011b040();
          }
          if (puVar3 == (undefined4 *)0x0) {
            return (undefined4 *)0x0;
          }
          FUN_4010bb10(puVar3);
          return (undefined4 *)0x0;
        }
        uVar8 = uVar5 + 3 & param_5;
        uVar6 = 0x5d4 - uVar8 & 0xffff;
        param_1[1] = (int)param_1 + uVar5 + 0x1b & 0xfffffffc;
        iVar7 = (uVar6 < uVar2) * uVar6 + (uVar6 >= uVar2) * uVar2;
        *param_1 = 0;
        param_1[3] = 0x10082;
        *(short *)(param_1 + 2) = (short)uVar2;
        *(short *)((int)param_1 + 10) = (short)iVar7;
        memw();
        param_1[4] = 0;
        param_1[5] = 0;
        puVar4 = puVar3;
      } while (uVar8 != 0x5d4);
      pcVar10 = "uf type";
      uVar9 = 0x107;
      iVar7 = in_t0;
    } while( true );
  }
LAB_4010bc4a:
  puVar3 = (undefined4 *)FUN_4010ba30(0,uVar2);
  return puVar3;
}

