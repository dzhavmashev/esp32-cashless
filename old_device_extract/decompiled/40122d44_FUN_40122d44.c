// Function : FUN_40122d44
// Address  : 0x40122d44
// Size     : 1171 bytes


undefined4 FUN_40122d44(undefined1 *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 in_EPC1;
  undefined1 in_EPC2;
  undefined1 in_EPC3;
  undefined1 in_EPC4;
  undefined1 in_EPC5;
  undefined1 in_EPC6;
  undefined1 in_EPS2;
  undefined1 in_EPS3;
  undefined1 in_EPS4;
  undefined1 in_EPS5;
  undefined1 in_EPS6;
  undefined4 uStack_28;
  int *apiStack_24 [9];
  
  uStack_28 = 0;
  apiStack_24[0] = (int *)0x0;
  if ((param_1 == (undefined1 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    memw();
    (*(code *)&SUB_40094c54)("/xtensa/core_dump_port.c",0x1ae,"id *)0)","_port.c");
  }
  uVar1 = FUN_40122cc0(param_1,&uStack_28,apiStack_24);
  DAT_3ffc7304 = *param_1;
  memw();
  DAT_3ffc7305 = param_1[1];
  memw();
  DAT_3ffc7306 = param_1[2];
  DAT_3ffc7307 = param_1[3];
  DAT_3ffc72f8 = 0;
  DAT_3ffc72f9 = 0;
  memw();
  if (uVar1 < 0x70) {
    memw();
    uVar2 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc170f,uVar2,0x3ffc1744,uVar1);
    uVar2 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc16e1,uVar2,0x3ffc1744);
  }
  else {
    if (*apiStack_24[0] == -0x21524111) {
      iVar3 = apiStack_24[0][0x14];
      DAT_3ffc7541 = (undefined1)((uint)iVar3 >> 8);
      DAT_3ffc7540 = (undefined1)iVar3;
      DAT_3ffc7542 = (undefined1)((uint)iVar3 >> 0x10);
      DAT_3ffc7543 = (undefined1)((uint)iVar3 >> 0x18);
      memw();
      iVar3 = apiStack_24[0][0x15];
      DAT_3ffc753c = 0xe8;
      DAT_3ffc7549 = (undefined1)((uint)iVar3 >> 8);
      DAT_3ffc754a = (undefined1)((uint)iVar3 >> 0x10);
      DAT_3ffc7548 = (undefined1)iVar3;
      DAT_3ffc754b = (undefined1)((uint)iVar3 >> 0x18);
      DAT_3ffc7544 = 0xee;
      DAT_3ffc753d = 0;
      DAT_3ffc753e = 0;
      DAT_3ffc753f = 0;
      DAT_3ffc7545 = 0;
      DAT_3ffc7546 = 0;
      DAT_3ffc7547 = 0;
      DAT_3ffc754c = 0xc2;
      DAT_3ffc754d = 0;
      DAT_3ffc754e = 0;
      DAT_3ffc754f = 0;
      uVar2 = rsr(in_EPS2);
      DAT_3ffc7551 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc7552 = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7550 = (undefined1)uVar2;
      DAT_3ffc7553 = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc7554 = 0xc3;
      DAT_3ffc7555 = 0;
      DAT_3ffc7556 = 0;
      DAT_3ffc7557 = 0;
      uVar2 = rsr(in_EPS3);
      DAT_3ffc7559 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc755a = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7558 = (undefined1)uVar2;
      DAT_3ffc755b = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc755c = 0xc4;
      DAT_3ffc755d = 0;
      DAT_3ffc755e = 0;
      DAT_3ffc755f = 0;
      uVar2 = rsr(in_EPS4);
      DAT_3ffc7561 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc7562 = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7560 = (undefined1)uVar2;
      DAT_3ffc7563 = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc7564 = 0xc5;
      DAT_3ffc7565 = 0;
      DAT_3ffc7566 = 0;
      DAT_3ffc7567 = 0;
      uVar2 = rsr(in_EPS5);
      DAT_3ffc7569 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc756a = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7568 = (undefined1)uVar2;
      DAT_3ffc756b = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc756c = 0xc6;
      DAT_3ffc756d = 0;
      DAT_3ffc756e = 0;
      DAT_3ffc756f = 0;
      uVar2 = rsr(in_EPS6);
      DAT_3ffc7571 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc7572 = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7570 = (undefined1)uVar2;
      DAT_3ffc7573 = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc7574 = 0xb1;
      DAT_3ffc7575 = 0;
      DAT_3ffc7576 = 0;
      DAT_3ffc7577 = 0;
      uVar2 = rsr(in_EPC1);
      DAT_3ffc7579 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc757a = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7578 = (undefined1)uVar2;
      DAT_3ffc757b = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc757c = 0xb2;
      DAT_3ffc757d = 0;
      DAT_3ffc757e = 0;
      DAT_3ffc757f = 0;
      uVar2 = rsr(in_EPC2);
      DAT_3ffc7581 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc7582 = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7580 = (undefined1)uVar2;
      DAT_3ffc7583 = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc7584 = 0xb3;
      DAT_3ffc7585 = 0;
      DAT_3ffc7586 = 0;
      DAT_3ffc7587 = 0;
      uVar2 = rsr(in_EPC3);
      DAT_3ffc7589 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc758a = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7588 = (undefined1)uVar2;
      DAT_3ffc758b = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc758c = 0xb4;
      DAT_3ffc758d = 0;
      DAT_3ffc758e = 0;
      DAT_3ffc758f = 0;
      uVar2 = rsr(in_EPC4);
      DAT_3ffc7591 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc7592 = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7590 = (undefined1)uVar2;
      DAT_3ffc7593 = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc7594 = 0xb5;
      DAT_3ffc7595 = 0;
      DAT_3ffc7596 = 0;
      DAT_3ffc7597 = 0;
      uVar2 = rsr(in_EPC5);
      DAT_3ffc7599 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc759a = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc7598 = (undefined1)uVar2;
      DAT_3ffc759b = (undefined1)((uint)uVar2 >> 0x18);
      DAT_3ffc759c = 0xb6;
      DAT_3ffc759d = 0;
      DAT_3ffc759e = 0;
      DAT_3ffc759f = 0;
      uVar2 = rsr(in_EPC6);
      DAT_3ffc75a1 = (undefined1)((uint)uVar2 >> 8);
      DAT_3ffc75a0 = (undefined1)uVar2;
      DAT_3ffc75a2 = (undefined1)((uint)uVar2 >> 0x10);
      DAT_3ffc75a3 = (undefined1)((uint)uVar2 >> 0x18);
      memw();
    }
    else {
      apiStack_24[0][0x15] = 0;
      apiStack_24[0][0x14] = 0xffff;
      if (*apiStack_24[0] == 0) {
        DAT_3ffc7334 = (undefined1)apiStack_24[0][1];
        memw();
        iVar3 = apiStack_24[0][2];
        DAT_3ffc7339 = (undefined1)((uint)iVar3 >> 8);
        DAT_3ffc7338 = (byte)iVar3;
        DAT_3ffc733a = (undefined1)((uint)iVar3 >> 0x10);
        DAT_3ffc733b = (undefined1)((uint)iVar3 >> 0x18);
        memw();
        uVar1 = apiStack_24[0][4];
        DAT_3ffc7435 = (undefined1)(uVar1 >> 8);
        DAT_3ffc7436 = (undefined1)(uVar1 >> 0x10);
        DAT_3ffc7437 = (undefined1)(uVar1 >> 0x18);
        DAT_3ffc7434 = (undefined1)uVar1;
        memw();
        iVar3 = apiStack_24[0][5];
        DAT_3ffc7439 = (undefined1)((uint)iVar3 >> 8);
        DAT_3ffc7438 = (undefined1)iVar3;
        DAT_3ffc743a = (undefined1)((uint)iVar3 >> 0x10);
        DAT_3ffc743b = (undefined1)((uint)iVar3 >> 0x18);
        memw();
        iVar3 = apiStack_24[0][6];
        DAT_3ffc743d = (undefined1)((uint)iVar3 >> 8);
        DAT_3ffc743c = (undefined1)iVar3;
        DAT_3ffc743e = (undefined1)((uint)iVar3 >> 0x10);
        DAT_3ffc743f = (undefined1)((uint)iVar3 >> 0x18);
        memw();
        iVar3 = apiStack_24[0][7];
        DAT_3ffc7441 = (undefined1)((uint)iVar3 >> 8);
        DAT_3ffc7442 = (undefined1)((uint)iVar3 >> 0x10);
        memw();
        uVar4 = apiStack_24[0][1] & 0x3fffffff;
        DAT_3ffc7335 = (undefined1)(uVar4 >> 8);
        DAT_3ffc7440 = (undefined1)iVar3;
        DAT_3ffc7443 = (undefined1)((uint)iVar3 >> 0x18);
        DAT_3ffc7336 = (undefined1)(uVar4 >> 0x10);
        DAT_3ffc7337 = (undefined1)(uVar4 >> 0x18);
        memw();
        if ((int)uVar1 < 0) {
          uVar1 = uVar1 & 0x3fffffff;
          DAT_3ffc7435 = (undefined1)(uVar1 >> 8);
          DAT_3ffc7436 = (undefined1)(uVar1 >> 0x10);
          DAT_3ffc7437 = (undefined1)(uVar1 >> 0x18);
          memw();
          memw();
        }
        goto LAB_40122dd4;
      }
    }
    DAT_3ffc7334 = (undefined1)apiStack_24[0][1];
    memw();
    DAT_3ffc7335 = *(undefined1 *)((int)apiStack_24[0] + 5);
    memw();
    DAT_3ffc7336 = *(undefined1 *)((int)apiStack_24[0] + 6);
    uVar1 = apiStack_24[0][2];
    memw();
    DAT_3ffc7337 = *(undefined1 *)((int)apiStack_24[0] + 7);
    DAT_3ffc7339 = (undefined1)(uVar1 >> 8);
    DAT_3ffc733a = (undefined1)(uVar1 >> 0x10);
    DAT_3ffc733b = (undefined1)(uVar1 >> 0x18);
    DAT_3ffc7338 = (byte)uVar1;
    memw();
    iVar3 = apiStack_24[0][3];
    DAT_3ffc7435 = (undefined1)((uint)iVar3 >> 8);
    DAT_3ffc7434 = (undefined1)iVar3;
    DAT_3ffc7436 = (undefined1)((uint)iVar3 >> 0x10);
    DAT_3ffc7437 = (undefined1)((uint)iVar3 >> 0x18);
    memw();
    DAT_3ffc7348 = (undefined1)apiStack_24[0][0x13];
    memw();
    DAT_3ffc7349 = *(undefined1 *)((int)apiStack_24[0] + 0x4d);
    memw();
    DAT_3ffc734a = *(undefined1 *)((int)apiStack_24[0] + 0x4e);
    iVar3 = apiStack_24[0][0x16];
    memw();
    DAT_3ffc734b = *(undefined1 *)((int)apiStack_24[0] + 0x4f);
    DAT_3ffc733d = (undefined1)((uint)iVar3 >> 8);
    DAT_3ffc733c = (undefined1)iVar3;
    DAT_3ffc733e = (undefined1)((uint)iVar3 >> 0x10);
    DAT_3ffc733f = (undefined1)((uint)iVar3 >> 0x18);
    memw();
    iVar3 = apiStack_24[0][0x17];
    DAT_3ffc7341 = (undefined1)((uint)iVar3 >> 8);
    DAT_3ffc7340 = (undefined1)iVar3;
    DAT_3ffc7342 = (undefined1)((uint)iVar3 >> 0x10);
    DAT_3ffc7343 = (undefined1)((uint)iVar3 >> 0x18);
    memw();
    iVar3 = apiStack_24[0][0x18];
    DAT_3ffc7345 = (undefined1)((uint)iVar3 >> 8);
    DAT_3ffc7344 = (undefined1)iVar3;
    DAT_3ffc7346 = (undefined1)((uint)iVar3 >> 0x10);
    DAT_3ffc7347 = (undefined1)((uint)iVar3 >> 0x18);
    memw();
    if ((uVar1 & 0x20) != 0) {
      DAT_3ffc7338 = DAT_3ffc7338 & 0xef;
      memw();
      memw();
    }
  }
LAB_40122dd4:
  *param_2 = 0x3ffc72ec;
  memw();
  return 0x24c;
}

