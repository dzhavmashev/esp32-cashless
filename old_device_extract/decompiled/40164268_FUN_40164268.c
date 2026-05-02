// Function : FUN_40164268
// Address  : 0x40164268
// Size     : 365 bytes


/* WARNING: Instruction at (ram,0x4016441d) overlaps instruction at (ram,0x4016441c)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x4016443f) */

void FUN_40164268(undefined1 *param_1,byte param_2,char param_3,undefined1 param_4,char param_5)

{
  int unaff_retaddr;
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  undefined **ppuVar5;
  uint uVar6;
  uint uVar7;
  uint in_a15;
  undefined4 in_t0;
  
  uVar7 = (uint)(byte)param_1[0x87];
  if ((DAT_3ffc1a44 != '\0') && (param_3 != '\0')) {
    memw();
    in_a15 = uVar7;
    FUN_40147fe4(6,0x200,2,0x3f4370f9,param_1[0x82],uVar7,(int)(char)param_2);
  }
  iVar1 = FUN_40164174(param_1,param_4,param_5);
  param_1[0x1a] = param_2;
  memw();
  if ((byte)param_1[0x82] < 7) {
    ppuVar5 = &switchD_401642c7::switchdataD_3f4246f0 + (byte)param_1[0x82];
switchD_401642c7_caseD_401642c2:
    ppuVar5 = (undefined **)*ppuVar5;
    memw();
    switch(ppuVar5) {
    case (undefined **)0x4016404e:
      *(ushort *)(param_1 + 0x7e) = (ushort)param_2;
      memw();
      memw();
      return;
    case (undefined **)0x40164054:
      cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    default:
      goto switchD_401642c7_caseD_401642c2;
    case (undefined **)0x40164398:
      uVar2 = func_0x400eb398();
      iVar1 = 0x3ffc0508;
      if (param_3 != '\0') {
        iVar1 = 0x3ffc04a8;
      }
      uVar4 = 7;
      *(int *)(param_1 + 0x70) = iVar1;
      param_1[4] = (char)uVar2;
      memw();
      if ((param_3 == '\0') && (uVar4 = 0xc, uVar7 == 0)) {
        uVar4 = 10;
      }
      param_1[5] = uVar4;
      memw();
      *(undefined4 *)(param_1 + 0x74) = 0x40163f4c;
      uVar4 = 8;
      if (param_3 == '\0') {
        uVar4 = 0xd;
      }
      param_1[6] = uVar4;
      memw();
      if ((char)param_2 < '\f') {
        uVar6 = 10;
        if (param_3 != '\0') {
          uVar6 = 7;
        }
      }
      else {
        uVar6 = 5;
        if ((('\x10' < (char)param_2) && (uVar6 = 3, '\x15' < (char)param_2)) &&
           (uVar6 = 0, (char)param_2 < '\x1e')) {
          uVar6 = 2;
          memw();
        }
      }
      if (param_5 != '\0') {
        uVar6 = uVar2;
      }
      *(uint *)(param_1 + 0x60) = (uVar6 & 0xffff) * 0xc + iVar1;
      puVar3 = &DAT_3ffc06d0;
      if (param_3 != '\0') {
        puVar3 = (undefined1 *)0x3ffc04fc;
      }
      *(undefined1 **)(param_1 + 100) = puVar3;
      memw();
      goto LAB_401644ae;
    case (undefined **)0x4016441d:
      cust0();
      param_1 = (undefined1 *)(uint)*(byte *)(unaff_retaddr + 0x91);
      *(undefined4 *)(in_a15 + 0x3c) = in_t0;
      *(undefined ***)(param_1 + 0x70) = &switchD_401642c7::switchdataD_3f4246f0;
      *(undefined ***)(param_1 + 0x60) = &switchD_401642c7::switchdataD_3f4246f0 + iVar1 * 3;
      memw();
      param_1[4] = (char)iVar1;
      memw();
      memw();
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x70) = 0x3ffc0460;
    *(undefined1 **)(param_1 + 0x60) = &DAT_3ffc0484;
    param_1[4] = 0;
  }
  uVar4 = 5;
  if (uVar7 == 0) {
    uVar4 = 3;
  }
  param_1[5] = uVar4;
  memw();
  *(undefined1 **)(param_1 + 0x74) = &LAB_40163f68;
  param_1[6] = 6;
  memw();
  *(undefined1 **)(param_1 + 100) = &DAT_3ffc0484;
  uVar6 = 0;
LAB_401644ae:
  if ((DAT_3ffc1a44 != '\0') && (param_3 != '\0')) {
    memw();
    FUN_40147fe4(6,0x200,2,0x3f4370cb,param_1[5],uVar6);
  }
  FUN_401641bc(param_1);
  *param_1 = 0x7f;
  param_1[1] = 0x7f;
  param_1[2] = 0x7f;
  param_1[3] = 0x7f;
  memw();
  puVar3 = &DAT_3ffc06c4;
  if (uVar7 == 0) {
    puVar3 = *(undefined1 **)(param_1 + 100);
  }
  *(undefined1 **)(param_1 + 0x68) = puVar3;
  memw();
  return;
}

