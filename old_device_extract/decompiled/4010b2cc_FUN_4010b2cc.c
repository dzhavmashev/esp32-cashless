// Function : FUN_4010b2cc
// Address  : 0x4010b2cc
// Size     : 416 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
FUN_4010b2cc(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 param_5,code *param_6,undefined4 param_7)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined4 *in_t0;
  
  if ((param_6 != (code *)0x0) && (param_1 != (undefined4 *)0x0)) {
    if (param_2 == (undefined4 *)0x0) {
      param_2 = &DAT_3f411ef4;
    }
    if (param_3 == (undefined4 *)0x0) {
      param_3 = &DAT_3f411ef4;
    }
    if (param_4 == (undefined4 *)0x0) {
      param_4 = &DAT_3f411ef4;
    }
    puVar6 = param_1 + 0x13;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    *(undefined1 *)(param_1 + 5) = 0;
    *(undefined1 *)(param_1 + 6) = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    *(undefined1 *)(param_1 + 0xb) = 0;
    *(undefined1 *)(param_1 + 0xc) = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    *(undefined1 *)(param_1 + 0x11) = 0;
    *(undefined1 *)(param_1 + 0x12) = 0;
    param_1[0x2e] = FUN_4018531c;
    puVar7 = param_1 + 0x26;
    puVar8 = param_1 + 0x25;
    do {
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      *(undefined1 *)(puVar6 + 4) = 0;
      *(undefined1 *)(puVar6 + 5) = 6;
      puVar6 = puVar6 + 6;
      *(undefined1 *)puVar8 = 0;
      memw();
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      *puVar7 = 0;
      puVar7[3] = 0;
      puVar7 = puVar7 + 1;
    } while (param_1 + 0x25 != puVar6);
    param_1[0x30] = FUN_40185314;
    *(undefined2 *)(param_1 + 0x38) = 0;
    *(undefined1 *)((int)param_1 + 0xeb) = 0;
    memw();
    memw();
    (*(code *)&SUB_4008b530)(param_1 + 0x32,0,0xc);
    *(undefined1 *)((int)param_1 + 0xef) = 1;
    memw();
    memw();
    FUN_40185508(param_1);
    param_1[0x31] = param_5;
    *(char *)((int)param_1 + 0xee) = DAT_3ffc632c;
    memw();
    param_1[0x3d] = 0;
    param_1[0x2d] = param_7;
    param_1[0x3e] = 0;
    param_1[0x3f] = 0;
    param_1[0x40] = 0;
    *(undefined2 *)(param_1 + 0x41) = 0;
    memw();
    memw();
    FUN_4010b270(param_1,param_2,param_3,param_4);
    cVar2 = (*param_6)(param_1);
    puVar7 = _DAT_3ffc83fc;
    if (cVar2 == '\0') {
      puVar6 = (undefined4 *)&DAT_3ffc83fc;
      puVar8 = (undefined4 *)0xff;
      *(undefined2 *)((int)param_1 + 0xe2) = *(undefined2 *)(param_1 + 0x38);
      memw();
      uVar3 = 0;
      do {
        if ((undefined4 *)(uint)*(byte *)((int)param_1 + 0xee) == puVar8) {
          *(undefined1 *)((int)param_1 + 0xee) = uVar3;
          memw();
        }
        iVar4 = 0x100;
        puVar5 = puVar7;
        while( true ) {
          if (puVar5 == (undefined4 *)0x0) {
            DAT_3ffc632c = '\0';
            if (*(char *)((int)param_1 + 0xee) != -2) {
              DAT_3ffc632c = *(char *)((int)param_1 + 0xee) + '\x01';
            }
            *param_1 = puVar7;
            bVar1 = *(byte *)((int)param_1 + 0xeb);
            memw();
            *puVar6 = param_1;
            if ((bVar1 & 0x20) == 0) {
              return param_1;
            }
            memw();
            FUN_40116384(param_1);
            return param_1;
          }
          if (puVar5 != param_1) goto LAB_4010b441;
          pcVar10 = "pointer";
          uVar9 = 0x195;
          puVar6 = in_t0;
          while( true ) {
            uVar3 = (*(code *)&SUB_40094c54)("d netif",uVar9,"_ipaddr",pcVar10);
            puVar8 = puVar6;
            in_t0 = puVar6;
LAB_4010b441:
            iVar4 = iVar4 + -1;
            if (iVar4 != 0) break;
            pcVar10 = "y added";
            uVar9 = 0x197;
            puVar6 = in_t0;
          }
          if (*(char *)((int)puVar5 + 0xee) == *(char *)((int)param_1 + 0xee)) break;
          puVar5 = (undefined4 *)*puVar5;
        }
        *(char *)((int)param_1 + 0xee) = *(char *)((int)puVar5 + 0xee) + '\x01';
        memw();
        memw();
      } while( true );
    }
  }
  return (undefined4 *)0x0;
}

